#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

string encrypt_message(string message, int key);
string decrypt_message(string message, int key);

int main() {
    string user_secret_message {};
    string encrypted_message{};
    string decrypted_message{};
    int encryption_key = 25;

    cout << "Please enter a secret message" << endl;
    getline(cin,user_secret_message);

    encrypted_message = encrypt_message(user_secret_message,encryption_key);
    cout << "Encrypted message is " << encrypted_message << endl;

    decrypted_message = decrypt_message(encrypted_message,encryption_key);
    cout << "Decrypted message is " << decrypted_message << endl;

    return 0;
}

string encrypt_message(string message, int key){

    for(int i=0 ; i < message.size() ; i++){
        message.at(i) += key; 
    }

    return message;
}

string decrypt_message(string message, int key){

    for(int i=0 ; i < message.size() ; i++){
        message.at(i) -= key; 
    }

    return message;
    
}