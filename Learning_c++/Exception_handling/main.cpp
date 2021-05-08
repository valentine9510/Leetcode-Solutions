#include <iostream>

using namespace std;

class DivideByZeroException {
    public:
        string msg {" Attempted to divide by zero"};
};

class NegativeException {
    public:
        string msg {"Negative value error"};
};

double calculate_mpg (int miles, int gallons){
    if (gallons == 0){
        throw DivideByZeroException();
    }
    if (gallons < 0 || miles < 0){
        throw NegativeException();
    }
    return static_cast<double>(miles)/gallons;
}

int main (){
    std::cout << std::boolalpha;
    std::cout << " boolalpha (10 == 20)" <<(10 == 20) << endl;
    std::cout <<  " boolalpha (20 == 20)"<<(20 == 20) << endl;
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
    catch (const DivideByZeroException &ex){
        cout << ex.msg << endl;
    }
    catch (const NegativeException &err){
        cout << err.msg << endl;
    }
    catch (...){
        cout << " Unknown exception";
    }
    

    

    cout << " Bye";
    return 0;
}