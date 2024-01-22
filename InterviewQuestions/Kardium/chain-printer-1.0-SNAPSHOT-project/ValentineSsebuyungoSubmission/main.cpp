/**
 * @author Valentine Ssebuyungo
 * @brief 
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ChainPrinter.h"
#include "ChainPrinterDriver.h"
#include "LoggingChainPrinterDriver.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // In C++, objects are usually created on the stack, but dynamic polymorphism
    // requires objects to be allocated on the heap.
    ChainPrinterDriver* driver = new LoggingChainPrinterDriver();
    ChainPrinter *printer = new ChainPrinter(driver); // ChainPrinter takes ownership of driver

    vector<string> testStrings =                {"00000000","01234567","01100101", "        ", "", "11", "11111111111111", "0123456789"};
    vector<string> expectedPrintStrings =       {"00000000","01      ","01100101", "        ", "", "11", "11111111", "01      "};
    vector<string> expectedDebugPrintStrings =  {"00000000","01%%%%%%","01100101", "        ", "", "11", "11111111", "01%%%%%%"};
    vector<string> expectedPadedPrintStrings =  {"00000000","01234567","01100101", "        ", "", "1#", "1#######", "01234567"};

    for(auto i = 0; i < testStrings.size(); i++){
        string toPrint = testStrings.at(i);
        cout << "Chain printer to print "<< toPrint << endl;
        cout << "_____ Test " << i << " Start _____" << endl;
        printer->println(toPrint);
        cout << "_____ Test " << i << " Normal Print Completed Expected String is " << expectedPrintStrings.at(i)  << "_____ \n\n" << endl;
    }

    for(auto i = 0; i < testStrings.size(); i++){
        string toPrint = testStrings.at(i);
        cout << "Chain printer to debug print "<< toPrint << endl;
        cout << "_____ Test " << i << " Start _____" << endl;
        printer->dprintln(toPrint);
        cout << "_____ Test " << i << " Debug Print  Completed Expected String is " << expectedDebugPrintStrings.at(i)  << " _____ \n\n" << endl;
    }

    for(auto i = 0; i < testStrings.size(); i++){
        string toPrint = testStrings.at(i);
        cout << "Chain printer to do padded print "<< toPrint << endl;
        cout << "_____ Test " << i << " Start _____" << endl;
        printer->pprintln(toPrint);
        cout << "_____ Test " << i << " Padded Print  Completed Expected String is " << expectedPrintStrings.at(i)  << "_____ \n\n" << endl;
    }
    

    // printer->dprintln("00000000");
    // printer->dprintln("01234567");
    // printer->pprintln("01100101");

    // No need to delete 'driver' as 'printer's destructor will handle it
    return 0;
}


/**
 * @brief Plan
 * 
 * Printer driver should have a way of keeping track of every step it takes. In that way it can know which solenoids are aligned.
 * Everytime we need to keep track of what kind of hammer is at what position.
 * 
 * We need to have a circular array of solenoid hammers and the starting index of the array. Every multiple of 3, we advance an index
 *
 * Solenoids are 3mm apart
 * Hammers are 4mm apart
 * 
 * Printing
 * Resize string to 8 characters
 * Keep boolean array of the string to keep track of which characters are hit
 * 
 * Calculate Hammer Positions, place in the array.
 * 0,1,2,3,4,5,6,7 millimeterDisplacementFromOrigin
 * 0,3,2,1,0,3,2,1 distance from origin
 * 
 * For any hammer position that is a multiple of 3, (Solenoid). It has the ability to strike.
 *          Strike if (hammer == character[solenoid index]) && (character[solenoid index] == false)
 * 
 *          Conditions to print
 *          It is 1 or 0
 *          It is a space
 *          It is neither 1 nor 0 nor a space
 * 
 * Strike until all characters have finished
 * 
 * Exit whenever the word is finished
 * 
 * Go to the next line
 * 
 * 
 * Assumptions :
 * The Chain Printer always starts from 0
 * Only strike if the Solenoid is directly over the top of the character
 * To keep 
 * 
 */