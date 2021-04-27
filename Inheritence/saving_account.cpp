#include "saving_account.h"
#include <iostream>

using namespace std;


Savings_Account::Savings_Account(double bal, double int_rate)
:Account(bal),int_rate{int_rate}{
}

Savings_Account::Savings_Account()
:Savings_Account{0.0,0.0}{
}

Savings_Account::~Savings_Account(){
}

void Savings_Account::deposit(double amount){
    amount = amount + (amount*int_rate/100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream& os, const Savings_Account &account){ 
    os << "Savings_Account balance" << account.balance << " Interest rate is : " << account.int_rate << std::endl;
    return os;
}