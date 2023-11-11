#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Function declaration */
void print_array(int array[]);
uint64_t fibonacci (uint64_t n);


int main()
{
    cout << fibonacci(50) << endl;
    return 0;
}

void print_array (int array_to_print[]){
    for (int i = 0; i <5; i++){
        cout << (*(array_to_print + i));
    }
    cout << endl;
}

uint64_t fibonacci ( uint64_t n){
    if (n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
