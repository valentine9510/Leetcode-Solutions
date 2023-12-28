#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void){
    vector<int> temp = {41,94,15,17,68,89};

    sort(temp.rbegin(), temp.rend());

    for (auto i : temp){
        cout << i << " ";
    }

    cout << endl;


}