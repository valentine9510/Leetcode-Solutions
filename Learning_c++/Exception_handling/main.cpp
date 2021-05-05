#include <iostream>

using namespace std;

double calculate_mpg (int miles, int gallons){
    if (gallons == 0){
        throw 0;
    }
    if (gallons < 0 || miles < 0){
        throw std::string{" Negative value error"};
    }
    return static_cast<double>(miles)/gallons;
}

int main (){
    int miles, gallons;
    double miles_per_gallon;

    cout << " Enter miles ";
    cin >> miles;
    cout << " Enter gallons ";
    cin >> gallons;

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        cout << " Miles per gallon is :" << miles_per_gallon << endl;
    }
    catch (int &exception){
        cout << " You cannot divide by zero \n";
    }
    catch (std::string &err){
        cout << err << endl;
    }
    catch (...){
        cout << " Unknown exception";
    }
    

    

    cout << " Bye";
    return 0;
}