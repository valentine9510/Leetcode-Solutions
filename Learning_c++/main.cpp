#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Function declaration */
void vector_practice (void);

int main()
{
    vector_practice();
}

void vector_practice (void){
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    vector<string> trial (5);
    vector<string> trial_2 {"Hello", "Hey", "Boujour"};
    vector<double> double_vector (50,30);


    //2D Vector
    vector<int> vector_one;
    vector_one.push_back(10);
    vector_one.push_back(20);

    vector<int> vector_two;
    vector_two.push_back(10);
    vector_two.push_back(20);

    vector<vector<int>> vector_2D;
    vector_2D.push_back(vector_one);
    vector_2D.push_back(vector_two);

    cout << "displaying vector 2D" << endl;
    for ( int i = 0; i < vector_2D.size(); i++){
        for (int j=0; j < vector_2D[i].size(); j++){
            cout << vector_2D.at(i).at(j) << "," ;
        }

        cout<<endl;
    } 

    cout << "Changing value in vector 1" << endl;
    vector_one.at(0) = 1000;

    cout << "displaying vector 2D" << endl;
    for ( int i = 0; i < vector_2D.size(); i++){
        for (int j=0; j < vector_2D[i].size(); j++){
            cout << vector_2D.at(i).at(j) << "," ;
        }

        cout<<endl;
    } 

    cout << "displaying vector one" << endl;

    for (int j=0; j < vector_one.size(); j++){
            cout << vector_one.at(j) << "," ;
    }
    cout << endl;


    vector <vector<int>> movie_ratings 
    {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {6,7,8,9,10}
    };

    for ( int i = 0; i < movie_ratings.size(); i++){
        for (int j=0; j < movie_ratings[i].size(); j++){
            cout << movie_ratings.at(i).at(j) << "," ;
        }

        cout<<endl;
    } 
    return;

    cout << msg.at(4) << endl;

    cout << "There are " << msg.size() << " elements in the msg vector" << endl;
    msg.push_back(" Pushedback");
    cout << "There are " << msg.size() << " elements in the msg vector" << endl;

    for (int j = 0; j < msg.size() ; j++){
        cout << msg.at(j);
    }
    cout << endl;

    cout << "Enter string messages" << endl;
    cin >> msg.at(0);
    cin >> msg.at(1);
    cin >> msg.at(2);

    for (int i = 0; i < msg.size() ; i++){
        cout << msg.at(i);
    }
    cout << endl;

     
}
  