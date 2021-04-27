//Include Guard
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H

#include <iostream>
#include <string.h>

class Account1 {
    private:
        std::string name;
        double balance;

    public:
        Account1();
        Account1(std::string name, double val);
        void Account1 (double balance);
        double get_balance (void); 
        void set_name(std::string name);
        bool deposit(double amount);
        bool withdraw(double amount);

};

class Player {
    private:
        std::string name;
        int health;
        int xp;
    public:
        Player(std::string,int , int );
        Player(std::string,int);
        Player(std::string);
        Player(const Player &other); //Copy constructor
        Player(Player &&source);
        ~Player();

        void set_name(std::string);
        std::string get_name(void) const;
};

#endif

