#include <iostream>
#include <string>
#include <map>

/**
 * @brief Task Description
interval_map<K,V> is a data structure that associates keys of type K with values of type V. It is designed to be used efficiently in situations where intervals of consecutive keys are associated with the same value. Your task is to implement the assign member function of this data structure, which is outlined below.

interval_map<K, V> is implemented on top of std::map. For more information on std::map, you may refer to cppreference.com.

Each key-value-pair (k,v) in interval_map<K,V>::m_map means that the value v is associated with all keys from k (including) to the next key (excluding) in m_map. The member interval_map<K,V>::m_valBegin holds the value that is associated with all keys less than the first key in m_map.

Example: Let M be an instance of interval_map<int,char> where

M.m_valBegin=='A',
M.m_map=={ (1,'B'), (3,'A') },
Then M represents the mapping

...
-2 -> 'A'
-1 -> 'A'
0 -> 'A'
1 -> 'B'
2 -> 'B'
3 -> 'A'
4 -> 'A'
5 -> 'A'
...
The representation in the std::map must be canonical, that is, consecutive map entries must not contain the same value: ..., (3,'A'), (5,'A'), ... is not allowed. Likewise, the first entry in m_map must not contain the same value as m_valBegin. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the interval_map<K,V> data structure.

Key type K

besides being copyable and assignable, is less-than comparable via operator<, and
does not implement any other operations, in particular no equality comparison or arithmetic operators.
Value type V

besides being copyable and assignable, is equality-comparable via operator==, and
does not implement any other operations.
You are given the following source code:

#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
       //Please insert your solution here

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

Your task is to implement the function assign. Your implementation is graded by the following criteria in this order:

Type requirements are met: You must adhere to the specification of the key and value type given above.
Correctness: Your program should produce a working interval_map with the behavior described above. In particular, pay attention to the validity of iterators. It is illegal to dereference end iterators. Consider using a checking STL implementation such as the one shipped with Visual C++ or GCC.
Canonicity: The representation in m_map must be canonical.
Running time: Imagine your implementation is part of a library, so it should be big-O optimal. In addition:

Do not make big-O more operations on K and V than necessary because you do not know how fast operations on K/V are; remember that constructions, destructions and assignments are operations as well.
Do not make more than one operation of amortized O(log N), in contrast to O(1), running time, where N is the number of elements in m_map.
Otherwise favor simplicity over minor speed improvements
 * 
 * @tparam K 
 * @tparam V 
 */
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		if((keyBegin < keyEnd) == false) return; //empty interval

		//Constraints 
			// consecutive map entries cannot contain the same value
			// First Entry in map cannot contain the same value as m_valBegin

		auto insertRes = m_map.insert(std::make_pair(keyBegin, val)); //insert value into the map, Log N

		auto lowerbound_it = insertRes.first; 
		auto itHigh = lowerbound_it; //m_map.lower_bound(keyEnd); //find the end of the ranges

		while (itHigh != m_map.end() && itHigh->first < keyEnd) //advance until the end of range
		{
			std::advance(itHigh,1);
		}
		

		std::advance(lowerbound_it,1);
		if(lowerbound_it != itHigh)	m_map.erase(lowerbound_it, itHigh);

		//Handle issue where first key has the value of m_begin
		if(m_map.begin()->second == m_valBegin){
			m_map.erase(m_map.begin());
		}

	}

	void assign_chatgpt(K const& keyBegin, K const& keyEnd, V const& val) {

	    if (!(keyBegin < keyEnd)) {
			return; // Empty interval, do nothing
		}

		// Handling the start of the interval
		auto itLow = m_map.lower_bound(keyBegin);
		if (itLow != m_map.begin() && std::prev(itLow)->second == val) {
			--itLow; // Merge with the previous interval if values are the same
		} else {
			if (keyBegin < m_map.begin()->first && val == m_valBegin) {
				m_map.erase(m_map.begin()); // Avoid duplicating m_valBegin
			} else {
				m_map[keyBegin] = val;
			}
		}

		// Handling the end of the interval
		auto itHigh = m_map.lower_bound(keyEnd);
		if (itHigh != m_map.begin() && std::prev(itHigh)->second == val) {
			m_map.erase(itLow, itHigh); // Remove redundant entries
		} else {
			if (keyEnd != m_map.begin()->first) {
				m_map[keyEnd] = std::prev(itHigh)->second;
				m_map.erase(itLow, itHigh);
			}
		}

		// Remove redundant entry at keyEnd if value equals the next interval's value
		auto it = m_map.find(keyEnd);
		if (it != m_map.end() && it->second == val) {
			m_map.erase(it);
		}
	}


	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

#include <iostream>

// Include the interval_map class definition here

int main() {
    interval_map<int, char> map('A');

    // Function to print test results
    auto printTestResult = [](char actual, char expected, const std::string& testDescription) {
        std::cout << testDescription << ": ";
        if (actual == expected) {
            std::cout << "Passed (Actual: " << actual << ", Expected: " << expected << ")" << std::endl;
        } else {
            std::cout << "Failed (Actual: " << actual << ", Expected: " << expected << ")" << std::endl;
        }
    };

    // Initial state (whole range associated with 'A')
    printTestResult(map[0], 'A', "Initial state at 0");
    printTestResult(map[-1], 'A', "Initial state at -1");
    printTestResult(map[100], 'A', "Initial state at 100");

    // Assign a range
    map.assign(1, 5, 'B');
    printTestResult(map[0], 'A', "Assign range 1-5 to 'B', test at 0");
    printTestResult(map[1], 'B', "Assign range 1-5 to 'B', test at 1");
    printTestResult(map[4], 'B', "Assign range 1-5 to 'B', test at 4");
    printTestResult(map[5], 'B', "Assign range 1-5 to 'B', test at 5");

    // Overlapping assignment
    map.assign(3, 7, 'C');
    printTestResult(map[2], 'B', "Overlapping assign 3-7 to 'C', test at 2");
    printTestResult(map[3], 'C', "Overlapping assign 3-7 to 'C', test at 3");
    printTestResult(map[6], 'C', "Overlapping assign 3-7 to 'C', test at 6");
    printTestResult(map[7], 'C', "Overlapping assign 3-7 to 'C', test at 7");

    // Assigning same value as m_valBegin
    map.assign(-3, 2, 'A');
    printTestResult(map[-3], 'A', "Assign same as initial value at beginning -3-2 to 'A', test at -3");
    printTestResult(map[-1], 'A', "Assign same as initial value at beginning -3-2 to 'A', test at -1");
    printTestResult(map[0], 'A', "Assign same as initial value at beginning -3-2 to 'A', test at 0");
	printTestResult(map[1], 'A', "Assign same as initial value at beginning -3-2 to 'A', test at 1");
	printTestResult(map[2], 'A', "Assign same as initial value at beginning -3-2 to 'A', test at 2");

    // Test empty interval
    map.assign(10, 10, 'D');
    printTestResult(map[9], 'C', "Empty assign 10-10 to 'D', test at 9");
    printTestResult(map[10], 'C', "Empty assign 10-10 to 'D', test at 10");

    // Test intervals that remove previous values
    map.assign(5, 8, 'A');
    printTestResult(map[4], 'C', "Assign 5-8 to 'A', test at 4");
    printTestResult(map[5], 'A', "Assign 5-8 to 'A', test at 5");
    printTestResult(map[7], 'A', "Assign 5-8 to 'A', test at 7");
    printTestResult(map[8], 'A', "Assign 5-8 to 'A', test at 8");

    // Test interval that extends beyond existing keys
    map.assign(15, 20, 'E');
    printTestResult(map[14], 'A', "Assign 15-20 to 'E', test at 14");
    printTestResult(map[15], 'E', "Assign 15-20 to 'E', test at 15");
    printTestResult(map[19], 'E', "Assign 15-20 to 'E', test at 19");
    printTestResult(map[20], 'E', "Assign 15-20 to 'E', test at 20");

    return 0;
}


// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.