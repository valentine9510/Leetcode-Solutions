#include "account.h"
#include "saving_account.h"
#include <iostream>
#include <vector>
#include <string>



using namespace std;

int main()
{
    Account a1(1000.0);

    Savings_Account s1{1000.0,5.0};
    s1.deposit(1000.0);
    s1.withdraw(200.0);
    s1.withdraw(100.0);
    return 0;
}