#include <iostream>
#include <memory.h>

using namespace std;

class Account{
public:
    virtual void withdraw()const {
        std::cout << "Withdraw :: Account " << endl;
    }
};

class Trust : public Account {
    public:
    virtual void withdraw()const {
        std::cout << "Withdraw :: Trust " << endl;
    }
};

class Checking : public Account {
    public:
    virtual void withdraw()const {
        std::cout << "Withdraw :: Checking " << endl;
    }
};

class Savings : public Account {
    public:
    virtual void withdraw()const {
        std::cout << "Withdraw :: Savings " << endl;
    }
};


/*void greetings(const Base &obj){
    cout << "Greetings";
    obj.say_hello();
}*/

int main(){
    std::cout <<  "\n === Pointers === " << endl;
    Account *p1 = new Account();
    Account *p2 = new Trust();
    Account *p3 = new Savings();
    Account *p4 = new Checking();

    p1->withdraw();
    p2->withdraw();
    p3->withdraw();
    p4->withdraw();

    /*Base b;
    b.say_hello();

    Derived  d;
    d.say_hello();

    greetings(b);
    greetings(d);

    Base *ptr = new Derived();
    ptr ->say_hello();
    delete ptr;*/

    return 0;
}
