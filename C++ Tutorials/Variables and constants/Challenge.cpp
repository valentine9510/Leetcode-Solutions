#include <iostream>

using namespace std;

int main() {
    const int charge_small_room = 25;
    const int charge_large_room = 35;
    const double tax = 6.00;
    const int valid_days = 30;

    cout << "Please enter how many small rooms you need ";
    int customer_large_rooms, customer_small_rooms = 0;
    cin >> customer_small_rooms;
    cout << "Please enter how many large rooms you need ";
    cin >> customer_large_rooms;
    int total = customer_small_rooms*charge_small_room + customer_large_rooms*charge_large_room;
    double tax_amount = total*tax/100;

    cout << "Estimation for the carpet cleaning service " << endl;
    cout << "Number of small rooms: " << customer_small_rooms << endl;
    cout << "Number of large rooms: " << customer_large_rooms << endl;
    cout << "Price per small room: $" << charge_small_room << endl;
    cout << "Price per large room: $" << charge_large_room << endl;
    cout << "Cost : $" << total << endl;
    cout << "Tax : $" << tax_amount << endl;
    cout << "=======================================================\n";
    cout << "Total estimate : $" << total + tax_amount << endl;
    cout << "This estimate is valid for " << valid_days << " days";




}