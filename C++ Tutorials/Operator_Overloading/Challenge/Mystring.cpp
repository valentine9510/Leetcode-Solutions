#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

bool Mystring::operator==(const Mystring rhs){
    return (strcmp(this->str,rhs.str) == 0);
}

bool  Mystring::operator!=(const Mystring rhs){
    return (strcmp(this->str,rhs.str) != 0);
}

bool  Mystring::operator<(const Mystring rhs){
    return (strcmp(this->str,rhs.str) < 0);
}

bool  Mystring::operator>(const Mystring rhs){
    return (strcmp(this->str,rhs.str) > 0);
}

Mystring  Mystring::operator+(const Mystring rhs){
    //char buf[ std::strlen(rhs.str) +  strlen(this->str) + 1];
    // char *buf = (char*) malloc((strlen(rhs.str) + strlen(this->str) + 1)*sizeof(char));
    char *buf = new char[(strlen(rhs.str) + strlen(this->str) + 1)];
    strcat(buf,this->str);
    strcat(buf,rhs.str);
    Mystring temp{buf};

    delete[] buf;

    return temp;
}

Mystring  Mystring::operator*(int n){
    // char *buf = (char*) malloc((n*strlen(this->str) + 1)*sizeof(char));
    char *buf = new char[(n*strlen(this->str) + 1)];

    while(n > 0){
        strcat(buf,this->str);
        n--;
    }

    Mystring temp{buf};
    delete [] buf;
    return temp;
}

Mystring &Mystring::operator*=(int n){
    delete this->str;
    *this = this->operator*(n);
    return *this;
}

Mystring &Mystring::operator+=(const Mystring rhs){
    delete this->str;

    *this = this->operator+(rhs);

    return *this;
}
