#include "Checking_Account.h"
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

Checking_Account::Checking_Account(std::string name, double balance)
:Account{name,balance} {}

Checking_Account::~Checking_Account(){

}

bool Checking_Account::withdraw(double amount) 
{
    return Account::withdraw(amount + this->withdrawFeee);
}

TrustAccount::TrustAccount(std::string name , double balance , double int_rate)
    : Savings_Account{name,balance,int_rate},withdrawLimitCount{3},withdrawLimitPercentageAmount{20.0} 
{

}

bool TrustAccount::withdraw(double amount){
    if (this->withdrawLimitCount < 0 || amount > (this->balance*(this->withdrawLimitPercentageAmount/100.0))) return false;

    this->withdrawLimitCount--;
    return Savings_Account::withdraw(amount);
}

bool TrustAccount::deposit(double amount){
    if (amount >= this->depositExtraAmount) amount+=this->depositExtra;

    return Savings_Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account){
    os << "[Trust Account: " << account.name << ": " << account.balance << ": " << account.int_rate <<"]";
    return os;
}