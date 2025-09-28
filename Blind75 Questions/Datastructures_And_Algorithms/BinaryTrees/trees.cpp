#include <gtest/gtest.h>
#include <list>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
 

using namespace std;

class MyCache
{
public:
	void cacheIt(int key, std::string value) {
		// m_data.insert(std::make_pair(key, value));
        this->lock.lock();
        m_data[key] = value;
        this->lock.unlock();
	}
    //expected, std::optional, std::expected
	std::string getIt(int key) {
		// for (auto it : m_data) {
		// 	if (it.first == key) {
		// 		return it.second;
		// 	}
		// }


        if(m_data.find(key) != m_data.end())
            return m_data[key];

        auto val = m_data.find(key);

        if (val == m_data.end())
            return "";
        
        return val->second;
	}
private:
	std::unordered_map<int, std::string> m_data;
    mutex lock;
};
 
TEST(MyCache, testit) {
	MyCache cache;
	cache.cacheIt(1, "a");
	cache.cacheIt(2, "aa");
    	cache.cacheIt(3, "aaa");
	auto value = cache.getIt(3);

	EXPECT_EQ(value, "aaa");
}

/**
 * @brief 
 * 
 * 
 * 
 * We are going to design a portion of a credit card system, limiting ourselves to tracking a user's purchases. We need to track data points such as:
*  Transaction date and time
*  Merchant
*  Transaction amount
*  The system needs to calculate the current month's balance owed.


 * 
 */

 //Multiple users -> transactions
 //Merchants
 //
 
 //Transaction --> date, time, amount, Merchant, User

 struct Time {
    int year;
    int month; 
    int day;
    int hour;
 };

 class Merchant {
    string name;
 };

 class User {
    vector<Transaction> orders;

    double calculate_months_balance(struct Time start, struct Time end){
        double total = 0;

        for(int i = 0; i < orders.size(); i++){
            if(orders.at(i).t >= start && orders.at(i).t < end )
                total += orders.at(i).amount;
        }


        for (auto & order : orders)



        return total;
    }
 };

 class Transaction {
    public :
        Time t;
        double amount;
        Merchant * merchant;
        User * user;

 };

 // Merchant -> who you buy
    // who have i transa
    // 

// User --> transactions
//    --> current_month_balance
class CreditCard {
    vector<User> orders;

 };


//credit