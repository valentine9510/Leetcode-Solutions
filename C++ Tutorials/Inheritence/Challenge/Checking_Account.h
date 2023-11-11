#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <string.h>
#include "Account.h"
#include "Savings_Account.h"


class Checking_Account : public Account
{
private:
    /* data */
    static constexpr const double withdrawFeee =1.5;
public:
    Checking_Account(std::string name, double balance);
    ~Checking_Account();
    bool withdraw(double amount);
};

class TrustAccount : public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &TrustAccount);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int depositExtra = 50;
    static constexpr int depositExtraAmount = 50;
    int withdrawLimitCount;
    double withdrawLimitPercentageAmount;

public:
    TrustAccount(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
    ~TrustAccount();
    bool deposit(double amount);
    bool withdraw(double amount);

};

#endif