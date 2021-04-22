#include <iostream>
#include "Operator_overloading.h"

//No-args constructor
Mystring::Mystring()
    :str{nullptr}{
        str = new char[1];
        *str = '\0';
    }

//Overloading constructor
Mystring::Mystring(const char *s)
    :str{nullptr}{
        if (s==nullptr){
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str,s);
        }
        
    }

//Copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}{
        str = new char[std::strlen(source.str)+1];
        std::strcpy(str,source.str);
    }

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout << "Using copy assignment " << std::endl;

    if (this == &rhs){
        return *this;
    }

    delete []str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str,rhs.str);

    return *this;
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout << "Using move assignment" << std::endl;

    if (this == &rhs){
     return *this;
    }
    delete []str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

//Overloaded equality operator
bool Mystring::operator== (const Mystring &rhs) const {
    return (std::strncmp (str,rhs.str) == 0);
}

//Make lower case
Mystring Mystring::operator-()const {
    char *buff = new char[std::strlen(str)+1];
    strcpy(buff,str);
    for (size_t i=0; i<std::strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;

    return temp;
}

//Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char [std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    Mystring temp {buff};
    delete[] buff;

    return temp;

}

//Destructor 
Mystring::~Mystring(){
    delete []str;
}

//Display method
void Mystring::display()const {
    std::cout << str << " : " << get_length() <<std::endl;
}

//Length returner
int Mystring::get_length() const { return std::strlen(str); }

//string getter 
const char *Mystring::get_str()const { return str; }