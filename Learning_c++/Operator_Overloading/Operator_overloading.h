//Include Guard
#ifndef _OPERATOR_OVERLOADING_H_
#define _OPERATOR_OVERLOADING_H_

#include <iostream>
#include <string.h>

class Mystring {

    //friend bool operator==(const Mystring &lhs,const Mystring &rhs);
    //friend bool operator-(const Mystring &obj);
    //friend bool operator+ (const Mystring &lhs,const Mystring &rhs);

    private:
        char *str;
    public:
        Mystring();
        Mystring(const char*s);
        Mystring(const Mystring &source); //Copy constructor
        Mystring(Mystring &&source); //Move constructor
        ~Mystring(); //Destructor

        Mystring &operator = (const Mystring &rhs); //Copy assignment
        Mystring &operator = (Mystring &&rhs); //Move assignment

        Mystring operator-() const;                   // Make lower case
        Mystring operator+(const Mystring &rhs) const; //concatenate
        bool operator==(const Mystring &rhs) const;    //equality
        //Binary operators take one param, unary take one

        void display() const;
        int get_length() const;
        const char *get_str() const;
};

#endif