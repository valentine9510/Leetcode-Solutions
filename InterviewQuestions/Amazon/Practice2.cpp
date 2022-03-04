#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include "PractiseQns.h"
#include "Practice2.h"

using namespace std;
int main(){
    vector<vector<int>> calendar (4, vector<int>(7,0));
    int data = 23;
    int &refData = data;

    cout << refData;
   
    return 0;
}

/**
 * @brief Plan for each swap, find the largest difference, swap those two
 */
vector <int> findMinArray(vector <int> arr, int k) {
  // Write your code here
    if(arr.size() < 2) return arr;

  while(k > 0){
    //Find biggest difference
    int elementOne = 0; int elementTwo = 0; int difference = INT_MIN;

    for(auto i = 1; i < arr.size(); i++){ //Find largest difference
       if((arr.at(i-1)-arr.at(i)) >= difference){
           difference = (arr.at(i-1)-arr.at(i));
           elementOne = i;
           elementTwo = i-1; //Get indices
       }             
    }

    //swap
    int temp = arr.at(elementOne);
    arr.at(elementOne) = arr.at(elementTwo);
    arr.at(elementTwo) = temp;

    k--;
  }
  
  return arr;
}

/**
 * @brief Plan is to get the total time
 * So start with a  
 */
int getTotalTime(vector <int> arr) {
   int solution = 0;
   int tempSum = 0;
   sort(arr.rbegin(),arr.rend()); //Sort

   for(int i = 0; i < arr.size(); i++){
       if(i < 2){
           solution+=arr.at(i); //Just add to solution until we first get 2 numbers
           tempSum = solution;
           continue;
       }

       tempSum = tempSum + arr.at(i); //just calculated the sum of array
       solution = solution + tempSum; //We want to start with the largest sums as we go
   }
  
  return solution;
}


/**
 * @brief Plan
 * Could use a queue but that is hard so use an ordered map as I can iterate
 * Add each element to map and if even number, get the 2 values and divide by 2
 * If odd, just use the middle element
 */
vector<int> findMedian(vector <int> arr) {
  // Write your code here
  multimap<int,int>maxHeap;
  vector<int> solution;

  for(auto i = 0; i < arr.size(); i++){
      maxHeap.insert(make_pair(arr.at(i),arr.at(i)));
        int mid = maxHeap.size()/2;
        auto iterator =  maxHeap.begin();
      if(maxHeap.size()%2 == 0){ //Even

        std::advance(iterator,mid-1);  //Advance iterator
        int value1 = iterator->first; //Get first value

        std::advance(iterator,1);  //Advance iterator
        int value2 = iterator->first; //Get second value

        solution.push_back((value2+value1)/2);

      } else {
          std::advance(iterator,mid); //Advance iterator
          int value1 = iterator->first; //Get second value
          solution.push_back(value1);

      }
  }
  
  return solution;
}

/**
 * @brief Plan is to count number of levels in the tree
 */
int countLevels(Node* root, int level){
    if(root == NULL) return level;

    return std::max(countLevels(root->left, level+1), countLevels(root->right,level+1));

}

int visibleNodes(Node* root) {
  // Write your code here
  return countLevels(root,0);
}

/**
 * @brief Plan
 * Use a priority queue
 * Scroll for each minute take the largest bag
 * Take largest bag, pop it off
 * Push back value/2
 */
int maxCandies(vector <int> arr, int k) {
  // Write your code here
  int solution =0;
  priority_queue<int>maxHeap;

  for(int i : arr)maxHeap.push(i);

  while(k > 0 && maxHeap.size() > 0){
      int maxValue = maxHeap.top();
      maxHeap.pop();
      maxHeap.push(maxValue/2);

      solution+=maxValue;  

    
      k--;
  }

  return solution;
  
}


/**
 * @brief Use a heap
 */
vector <int> findMaxProduct(vector <int> arr) {
  // Write your code here
  vector<int> solution;
  priority_queue<int, vector<int>>maxHeap;

  for(auto i = 0; i < arr.size(); i++){
      maxHeap.push(arr.at(i));
      if(maxHeap.size() < 3) solution.push_back(-1);
      else {
          int first = maxHeap.top(); maxHeap.pop();
          int second = maxHeap.top(); maxHeap.pop();
          int third = maxHeap.top(); maxHeap.pop();

          solution.push_back(first*second*third);
          maxHeap.push(first); maxHeap.push(second); maxHeap.push(third);
      }
  }
  
  return solution;
}


/**
 * @brief Use a map
 */
int numberOfWays(vector<int>& arr, int k) {
  // Write your code here
  map<int,int> freqMap;
  int solution = 0;

  for(int i =0; i < arr.size(); i++){
      freqMap[arr.at(i)]++;
  }

  for(int i=0; i < arr.size(); i++){
      solution += freqMap[k-arr.at(i)];

      if(k-arr[i] == arr[i]) solution--;
  }

  return solution/2;
  
}

/**
 * @brief Plan
 * Plan for each number in array
 * Go left
 * Go right looking
 * 
 * OR create sub-arrays of size (n to 1) and then look through them
 * @param arr 
 * @return vector<int> 
 */
vector<int> CountSubarrays(vector <int> arr) {
  // Write your code here
  vector<int> solution (arr.size(),0);


  for(int i = 0; i < arr.size(); i++){
      solution.at(i)++; //first subarray of itself
      int left = i-1; int right=i+1;

      //Go left
    while (left >= 0)
    {
        //If the number is less than the current one add one to solution
        if(arr.at(left) <= arr.at(i)){
            solution.at(i)++;
        } 
        else {
            break; //No longer going to be the smallest
        }
        left--;
    }
    
      //Go right
      while (right < arr.size())
      {
        if(arr.at(right) <= arr.at(i)){
            solution.at(i)++;
        } 
        else {
            break; //No longer going to be the largest
        }
        right++;
      }
      
  }
  
  return solution;
}

string rotationalCipher(string input, int rotationFactor) {
  // Write your code here
    int letterRotationFactor = rotationFactor%26;
    int numberRotFactor = rotationFactor%10;

  for(auto i = 0; i < input.size(); i++){
      if(isalpha(input.at(i))){
        bool isCharLower = islower(input.at(i));
        char temp = tolower(input.at(i));

        temp = 'a' + ((temp - 'a') + letterRotationFactor)%26;

        if(!isCharLower) input.at(i) = toupper(temp);
        else input.at(i) = temp;

      } else if (isdigit(input.at(i))){
          input.at(i) = '0' + ((input.at(i) - '0') + numberRotFactor)%10;
      }
  }

  return input;
}

/**
 * @brief Plan
 * Use a deque and a set or 2 pointers and a set
 */
int characterReplacement(string s, int k) {
      return 0;  
}

/**
 * @brief Plan 
 * Brute force n^3
 * 
 * More effecient
 * Sort input array
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
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i+1; 
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
                while (nums[left]==nums[left-1] && left < right) 
                {
                    left++; //Update left pointer
                }
                
            }
        }
    }

    return soln;
        
}

/** The idea here is to create n-distance between slow and fast pointer, 
 * so that when we'll iterate through the sll, FAST will hit NULL before SLOW. By that time, 
 * SLOW will be essentially n nodes behind FAST, which we want to delete;
 * 
 * */
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev_slow=head; // This node-pointer will help in deleting the element
		
        /* size of the sll will definitely be greater than n. 
		So, we start size with n and later if there are more elements, 
		we'll increase in later iterations*/
        int size=n;
        
    // creating the n distance between slow and fast
        for(int i=0;i<n;i++) 
            fast=fast->next;
        
    // iteration to reach the element, which needed to be deleted
        while(fast!=NULL){
            prev_slow=slow;
            slow=slow->next;
            fast=fast->next;
            size++;
        }
        
        // Checking edge case... if the 1st element is needed to be deleted
        if(n==size) 
            return head->next;
        
        prev_slow->next=slow->next; // Deleting the element
        return head;
    }

bool containsDuplicate(vector<int>& nums){
    set<int> checker;

    for(auto i=0; i < nums.size(); i++){
        if (checker.insert(nums[i]).second == false) return true; 
        //Attempt to insert and if we fail return false
    }

    return false;
}

/**
 * @brief If length is not the same return false;
 * sort s, sort t
 * compare character by char
 */
bool isAnagram(string s, string t) {
       if(s.size() != t.size()) return false;
       sort(s.begin(),s.end()); 
       sort(t.begin(),t.end());

       return (s==t);
}

/**
 * @brief 
 * 
 */
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix (nums.size(),0);
        vector<int> postfix (nums.size(),0);
        vector<int> solution;

        for(auto i = 0; i < nums.size(); i++){
            if(i == 0) prefix[i] = nums[i];
            else prefix[i] = (nums[i]*prefix[i-1]);
        }

        for(auto i = nums.size()-1; i >= 0; i--){
            if(i == (nums.size()-1)) postfix[i] = nums[i];
            else postfix[i] = (nums[i]*postfix[i+1]);
        }

        for(auto i = 0; i < nums.size(); i++){
            int prefixNumber, postfixNumber;

            //Get prefix
            if(i == 0) prefixNumber = 1;
            else prefixNumber = prefix[i-1];

            //Get postfix
            if(i == nums.size()-1) postfixNumber = 1;
            else postfixNumber = postfix[i+1];

            solution.push_back(postfixNumber*prefixNumber);
        }

        return solution;
    }

/**
 * @brief Reverse a linked list, can use iteration and recursion
 * 
 */
ListNode* reverseList(ListNode* head){
    if(head == NULL) return head;

    ListNode*prev = NULL;
    ListNode* current = head;
    ListNode *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;

    /* With recursion */
    // if(head == NULL){
    //     return head; //Base case
    // }

    // reverseList(head->next);
    // ListNode* temp = head->next;
    // temp->next = head;
    // head->next = NULL;
    
}

/**
 * @brief Plan
 * Loop through the list and change the value at the node, if the next value is something I set to, then there is a cycle
 * Have a set that can store nodes, if the value is in the set, there is a cycle
 * 
 * @param head 
 * @return true 
 * @return false 
 */
bool hasCycle(ListNode *head) {
    set<ListNode *> chest;

    while(head != NULL){
        if (chest.insert(head).second == false ) return true; //Value node is in the set
        head=head->next;
    }

    return false;
}

/**
 * Plan
 * Start with max index = 0
 * Keep track of the last max height index and the maxArea
 * 
 * More efficient algorithm : 2 pointer approach
 * We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. 
 * Futher, we maintain a variable maxarea to store the maximum area obtained till now. 
 * At every step, we find out the area formed between them, update 
 * maxarea and move the pointer pointing to the shorter line towards the other end by one step.
 */
int maxArea(vector<int>& height) {
    // int maxArea = 0;

    // for(auto i = 0; i < height.size(); i++){
    //     for(auto j = i; j < height.size(); j++){
    //         int tempArea = std::min(height[i],height[j])*abs(i-j);
    //         if( tempArea > maxArea) maxArea = tempArea;
    //     }
    // }

    // return maxArea;

    int maxArea = 0, left = 0, right = height.size()-1;

    while(left < right){
        int tempArea = std::min(height[left],height[right])*abs(left-right);
        maxArea = std::max(maxArea,tempArea);
        if(height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}
/**
 * @brief Plan
 * Use binary search to look for minimum element in the array 
 */
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    int minIndex;


    while(low <= high){
        //Condition 1 found min
        if(nums.at(low) <= nums.at(high)){
            minIndex = low;
            break;
        }
        int mid = (low+high) /2;
        int next = (mid+1)%nums.size(); int prev = (mid+nums.size()-1)%nums.size();
        if(nums.at(mid) <= nums.at(next) && nums.at(mid) <= nums.at(prev)){
            minIndex = mid;
            break;
        } else if (nums.at(mid) <= nums.at(high)){
            high = mid-1;
        } else if (nums.at(mid) >= nums.at(low)){
            low = mid+1;
        }

    }

    return nums.at(minIndex);
        
}

