#include <iostream>
#include <vector>
#include <string>
#include "headers.h"

using namespace std;

/* Function declaration */
class Player2
{
public:
    //Attributes
    string name{"Player"};
    int health;
    int experience;

    //methods
    void talk(string text){
        cout << name << " says " << text << endl;
    }
    bool is_dead();

};

int main()
{
    Player2 frank;
    Player2 Hero;

    frank.name = "Frank";
    frank.health = 100;
    frank.experience = 12;
    frank.talk("You are awesome");

    Player2 players[]{frank,Hero};
    vector<Player2> Player_vec {frank};
    Player_vec.push_back(Hero); 

    Player2 *enemy{nullptr};
    enemy = new Player2;
    enemy->name = "Valentine";
    enemy->health = 200;
    enemy->talk("I am going to be a great programmer");
    delete enemy;

}