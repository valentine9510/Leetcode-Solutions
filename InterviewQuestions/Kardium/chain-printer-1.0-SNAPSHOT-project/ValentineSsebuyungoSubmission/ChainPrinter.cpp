#include "ChainPrinter.h"
#include <algorithm>

using namespace std;

ChainPrinter::ChainPrinter(ChainPrinterDriver* driverModule) : driver(driverModule), millimeterDisplacementFromOrigin(0) {}

ChainPrinter::~ChainPrinter() {
    delete driver;
}

void ChainPrinter::println(const std::string& line) {
    this->chainPrinterUniversalPrint(line,false);
}

void ChainPrinter::dprintln(const std::string& line) {
    this->chainPrinterUniversalPrint(line,true); //handle unknownCharacter
}

void ChainPrinter::pprintln(const std::string& line) {
    // REPLACE THIS WITH YOUR CODE
    println(line);
}

void ChainPrinter::chainPrintStep(int numberOfSteps){
    
    for(int i = 0; i < numberOfSteps; i++){
        if(this->driver){
            this->driver->step();
            this->millimeterDisplacementFromOrigin = (this->millimeterDisplacementFromOrigin + 1)%(this->distanceBtnHammers*2); //cycle between 0 and 7
        }
    }

}

void ChainPrinter::chainPrinterUniversalPrint(const std::string& line, bool unknownCharacterHandle) {
    string printedString = "********";
    std::string lineToPrint = line.substr(0,8); //get first 8 characters of line
    printedString.resize(lineToPrint.size());
    

    vector<bool> printedCharacterChecker (lineToPrint.size(), false); //initialise array to false


    // Additional code to handle 'line' if needed
    while(std::any_of(printedCharacterChecker.begin(), printedCharacterChecker.end(), [](bool x) { return (x == false);})) {
        //if any of the values have not been printed

        //calulcate hammer positions
        for(int i = 0; i < this->numOfSolenoids; i++){
            char evenIndexHammer = '0';
            char oddIndexHammer = '1';
            if(this->millimeterDisplacementFromOrigin > (this->distanceBtnHammers-1)){
                evenIndexHammer = '1';
                oddIndexHammer = '0';
            }

            /**
             * @brief 
             * 0,1,2,3,4,5,6,7 millimeterDisplacementFromOrigin
             * 0,3,2,1,0,3,2,1 distance from origin
             * Formula is (2*hammerDistance - displacement)%hammerdistance
             * 
             */
            int distanceFromOrigin = ((2*this->distanceBtnHammers - this->millimeterDisplacementFromOrigin)%this->distanceBtnHammers) + i*this->distanceBtnHammers;

            //if the distance from the origin is a multiple of 3mm, the solenoid can strike
            int solenoidIndex = (distanceFromOrigin/this->distanceBtnSolenoids)%(this->numOfSolenoids);

            if( solenoidIndex < lineToPrint.size() && distanceFromOrigin%this->distanceBtnSolenoids == 0){ //only if we can print
                //A solenoid can strike
                // int solenoidIndex = (distanceFromOrigin/this->distanceBtnSolenoids)%(this->numOfSolenoids);
                char hammerCharacter = (i%2 == 0)? evenIndexHammer : oddIndexHammer;

                //solenoid index is same as letter index
                if(printedCharacterChecker[solenoidIndex] == false ){
                    bool updateSystem = false;
                    if(lineToPrint.at(solenoidIndex) == hammerCharacter){
                        
                        //strike solenoid
                        if(driver) driver->fire(solenoidIndex);

                        updateSystem = true;

                        //update printed string
                        printedString.at(solenoidIndex) = lineToPrint.at(solenoidIndex);

                    } else if (lineToPrint.at(solenoidIndex) == ' '){
                        //leave a space
                        updateSystem = true;

                        //update printed string
                        printedString.at(solenoidIndex) = lineToPrint.at(solenoidIndex);
                    } else if (lineToPrint.at(solenoidIndex) != '1' && lineToPrint.at(solenoidIndex) != '0' && lineToPrint.at(solenoidIndex) != ' '){
                        //leave a space
                        updateSystem = true;


                        if(unknownCharacterHandle){
                            //strike solenoid
                            if(driver) driver->fire(solenoidIndex);
                            
                            //update step by 4mm and strike the same solenoid to have an inverse character
                            this->chainPrintStep(4);

                            //strike solenoid
                            if(driver) driver->fire(solenoidIndex);

                            //update printed string
                            printedString.at(solenoidIndex) = '%';
                        } else {
                            //leave a space

                            //update printed string
                            printedString.at(solenoidIndex) = '+';
                        }
                    }

                    if(updateSystem){ // we had a successful strike
                        printedCharacterChecker[solenoidIndex] = true;
                        this->chainPrintStep(1);
                    }
                    
                }
            }
        }

        //chain step incase there were no changes
        this->chainPrintStep(1);

    }

    driver->linefeed(); //skip to next line
    cout << "printedString : " << printedString << endl;
}