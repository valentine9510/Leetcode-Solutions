#include "headers.h"
#include <string>

void Account1::Account1(double bal){
    balance = bal;
}

double Account1::get_balance(void){
    return balance;
}

void Account1::set_name(std::string name){

}

bool Account1::deposit(double amount){
    balance += amount;
    return true;
}

bool Account1::withdraw(double amount){
    if (amount < balance){
        balance -+ amount;
        return true;
    }
    return false;
}


Player::Player(std::string name_val)
    :Player{name_val,0,0}{} //Delegating constructors

Player::Player(std::string name_val,int health_val)
    :Player{name_val,health_val,0}{} //Delegating constructors

Player::Player(std::string name_val,int health_val, int xp_val)
    :name {name_val}, health {health_val}, xp {xp_val} {}

Player::Player(const Player &other)
    //:name{other.name},health{other.health},xp{other.xp} {}
    // OR
    :Player{other.name,other.health,other.xp}{}