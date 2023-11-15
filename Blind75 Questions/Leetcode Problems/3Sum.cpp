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

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief Plan 
 * Brute force n^3
 * 
 * More effecient
 * Sort input array to avoid duplicates nLogn
 * Set first value to beginning
 * Use a Left pointer and right pointer to find a sum that = 0
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    // vector<vector<int>> soln;

    // for(auto i = 0; i < nums.size(); i++){
    //     for(auto j = 0; j < nums.size(); j++){
    //         for(auto k = 0; k < nums.size(); k++){
    //             if(i != j && i !=k && j!=k && nums[i]+nums[j]+nums[k] == 0){
    //                 vector<int> temp = {nums[i], nums[j], nums[k]};
    //                 sort(temp.begin(), temp.end());

    //                 if(std::find(soln.begin(),soln.end(),temp) == soln.end()){
    //                     soln.push_back(temp);
    //                 }  
    //             }
    //         }
    //     }
    // }

    //

    //return soln;

    vector<vector<int>> soln;
    sort(nums.begin(), nums.end()); //sort in ascending order

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) continue; //trying to avoid using the same value twice
        int left = i+1; //two pointer solution
        int right = nums.size()-1;

        while (left < right) {
            int total = nums[i]+nums[left]+nums[right];
            if(total > 0){
                right--;
            } else if (total <  0){
                left++;
            } else {
                soln.push_back({nums[i],nums[left],nums[right]});
                left++; //Update left pointer in case there are other values that could sum up
                while (nums[left]==nums[left-1] && left < right) //we only have to update left pointer, this is to avoid duplicate values
                {
                    left++; //Update left pointer
                }
                
            }
        }
    }

    return soln;
        
}


int main(){
    Solution soln;
    string s = "abcabcbb";
    cout << "Solution : lengthOfLongestSubstring in " << s << " is " << soln.lengthOfLongestSubstring(s) << endl;
    return 0;
}
