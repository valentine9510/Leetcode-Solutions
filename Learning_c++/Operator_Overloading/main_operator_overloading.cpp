#include <iostream>
#include "Operator_overloading.h"

using namespace std;

int main(){

    // Mystring empty;
    // Mystring larry("Larry");
    // Mystring stooge{larry};

    Mystring a {"Hello"};
    Mystring b;
    std::cout << b.get_str();
    b=a;
    std::cout << b.get_str();
    b = "Today";
    std::cout << b.get_str();
    return 0;
}