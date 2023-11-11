#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Function declaration */
void display (vector<string> *v){
    for (auto i: *v){
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    int i{5};
    while (i<0){
        cout << i << endl;
        i--;
    }
    
    int x{100},y{200};
    cout << "\nx" << x << endl;

    vector<string> stogoes = {"Hi", "tHERE"};
    display(&stogoes);


    return 0;
}
