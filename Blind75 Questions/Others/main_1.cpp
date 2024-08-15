#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>
#include "PractiseQns.h"
#include "Practice2.h"

using namespace std;
int main(){
    cout << "Hello" << endl;
    cout << "Min operations on {3,1,2} : " << minOperations({3,1,2});
   
    return 0;
}

/**
 * @brief There are 2 solutions. The better one is to just use another string where you push to the front.
 * 
 * @param a 
 * @param b 
 * @return string 
 */
string addBinary(string a, string b) {
        //get a
        long long int a_value = 0;
        long long int b_value = 0;

        for(char i : a){
            if(i == '1') a_value = a_value|1;
            a_value <<= 1;
        }
        a_value >>= 1;

        for(char i : b){
            if(i == '1') b_value = b_value|1;
            b_value <<= 1;
        }
        b_value >>= 1;

        long long int total = a_value+b_value;

        string answer;

        while (total > 0)
        {
            if(total&1 == 1){ //there is a 1
                answer.insert(0,"1");
            } else {
                answer.insert(0,"0");
            }

            total = total >> 1;
        }

        if(answer.size() == 0){
            answer.insert(0,"0");
        }

        return answer;
    }

/**
@brief Effecient solution
We start by initializing two variables: maxSum and currentSum.
maxSum represents the maximum sum encountered so far and is initially set to the minimum possible integer value 
to ensure that any valid subarray sum will be greater than it.

currentSum represents the current sum of the subarray being considered and is initially set to 0.

We iterate through the nums array using a for loop, starting from the first element and going up to the last element.

For each element in the array, we add it to the current sum currentSum. This calculates the sum of the subarray ending at the current element.

Next, we check if the current sum currentSum is greater than the current maximum sum maxSum.

If it is, we update maxSum with the new value of currentSum. This means we have found a new maximum subarray sum.

If the current sum currentSum becomes negative, it indicates that including the current element in the subarray would reduce the overall sum. 

In such cases, we reset currentSum to 0. This effectively discards the current subarray and allows us to start a fresh subarray from the next element.
We repeat steps 3 to 5 for each element in the array.

After iterating through the entire array, the variable maxSum will contain the maximum subarray sum encountered.

Finally, we return the value of maxSum as the result, representing the maximum sum of a contiguous subarray within the given array nums.

https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d

"local_maximum at index i is the maximum of A[i] and the sum of A[i] and local_maximum at index i-1."

Consider the array [-8, -3, -6, -2, -5, -4].

Initialize: max_current = -8, max_global = -8
Iteration:
i = 1: max_current = max(-3, -8 + -3) = -3, max_global = max(-8, -3) = -3
i = 2: max_current = max(-6, -3 + -6) = -6, max_global = max(-3, -6) = -3
i = 3: max_current = max(-2, -6 + -2) = -2, max_global = max(-3, -2) = -2
i = 4: max_current = max(-5, -2 + -5) = -5, max_global = max(-2, -5) = -2
i = 5: max_current = max(-4, -5 + -4) = -4, max_global = max(-2, -4) = -2

Example
Consider the array [-2, 1, -3, 4, -1, 2, 1, -5, 4].

Initialize: max_current = -2, max_global = -2
Iteration:
i = 1: max_current = max(1, -2 + 1) = 1, max_global = max(-2, 1) = 1
i = 2: max_current = max(-3, 1 - 3) = -2, max_global = max(1, -2) = 1
i = 3: max_current = max(4, -2 + 4) = 4, max_global = max(1, 4) = 4
i = 4: max_current = max(-1, 4 - 1) = 3, max_global = max(4, 3) = 4
i = 5: max_current = max(2, 3 + 2) = 5, max_global = max(4, 5) = 5
i = 6: max_current = max(1, 5 + 1) = 6, max_global = max(5, 6) = 6
i = 7: max_current = max(-5, 6 - 5) = 1, max_global = max(6, 1) = 6
i = 8: max_current = max(4, 1 + 4) = 5, max_global = max(6, 5) = 6
Result: The maximum sum of the contiguous subarray is 6.
 * 
 * @param nums 
 * @return int 
 */
int maxSubArray(vector<int>& A) {
    int max_local = A[0];
    int max_global = A[0];

    for (size_t i = 1; i < A.size(); ++i) {
        max_local = std::max(A[i], max_local + A[i]); //either the higher of the new_value OR the curr_sub_array_sum + new_value
        if (max_local > max_global) {
            max_global = max_local;
        }
    }
    return max_global;
}

int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
}

/**
 * @brief Start with the largest subarray
 * Use a sliding window to find the largest sum
 * This is not effecient
 * 
 * @param nums 
 * @return int 
 */
int maxSubArray(vector<int>& nums) {
    int largestSubArray = INT_MIN;
    if(nums.size() == 0) return 0;

    for(int sizeOfArray = 1; sizeOfArray<= nums.size(); sizeOfArray++){
        for(int startIndex = 0; startIndex < nums.size(); startIndex++){
            int endIndex = startIndex+sizeOfArray - 1; //end index

            if(endIndex >= nums.size()) break; //bound conditions

            //sum up values in my sliding window
            int tempSum = 0;
            for(int i = startIndex; i <= endIndex; i++){
                tempSum+=nums.at(i);
            }

            largestSubArray = max(largestSubArray, tempSum);
        }
    }

    return largestSubArray;
    
}

unordered_map<int, int> climbStairs_pathways;
int climbStairs(int n) {
    if(n <= 2) return n;

    if(climbStairs_pathways.find(n) != climbStairs_pathways.end()){ //if we have already calculated this value, do not calculate again
        return climbStairs_pathways[n];
    }
    
    climbStairs_pathways[n] = climbStairs(n-1) +  climbStairs(n-2); //store value in map to stop redoing things
    return climbStairs_pathways[n];
}

int findBSTHeight(TreeNode* root){
    if(root == NULL) return 0;

    int leftHeight = findBSTHeight(root->left);
    int righttHeight = findBSTHeight(root->right);

    if(leftHeight == -1 || righttHeight == -1 || (abs(leftHeight - righttHeight)>1)){
        return -1; //unequal
    }

    return 1 + max(leftHeight, righttHeight);
}

/**
 * @brief Find height of left and height of right
 * Difference should be less than one
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    return (findBSTHeight(root) != -1 );
}

/**
 * @brief Use binary search to make it fast
 * 
 * @param n 
 * @return int 
 */
bool isBadVersion(int i){
    return true;
}
int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    int firstBad = n;

    while (low <= high)
    {
        int mid = (high+low)/2;

        if(isBadVersion(mid)){
            firstBad = min(mid, firstBad); //update minimum
            high = mid-1; //go left to find first bad version
        } else {
            //if it a good one, then go right to find the first bad one
            low = mid+1;
        }
    }

    return firstBad;        
}

/**
 * @brief Place magazine in map, key is char; value is number of times that char occurs
 * Go through every value in the ransomNote, if it found in the map and the value of chars is more than 0 then move to next value
 * return true if you manage to complete ransomNote
 * 
 */

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> magazineStore;

    for(char i : magazine){ //update store magazine
        if(magazineStore.find(i) == magazineStore.end()){
            //not in magazine
            magazineStore.insert(make_pair(i,1));
        } else {
            magazineStore.at(i)++; //else add on the count
        }
    }

    //now go through ransomNote
    for(int i = 0; i < ransomNote.size(); i++){
        if(magazineStore.find(ransomNote[i]) == magazineStore.end()){
            return false; //not in map
        } else {
            //in map
            magazineStore.at(ransomNote[i])--;

            if(magazineStore.at(ransomNote[i]) < 0){
                return false;
            }
        }
    }

    return true;
}

/**
 * @brief Iterate through array, place values into map keeping track of the frequency
 * 
 * @param nums 
 * @return int 
 */
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> store;
    int maxElement = nums.at(0);
    int maxFreqency = 0;

    for(int i = 0; i < nums.size(); i++){
        if(store.find(nums.at(i)) == store.end()){
            store.insert(make_pair(nums.at(i),1));
        } else {
            store.at(nums.at(i))++;
        }

        if(store.at(nums.at(i)) > maxFreqency){
            maxFreqency = store.at(nums.at(i));
            maxElement = nums.at(i);
        }
    }

    return maxElement;
}

/**
 * @brief Pop all elements onto a queue or vector, in pair format <number, original index>
 * Find the first largest Value
 * Remove it 
 * For each of the elements, if greater than 0, remove -1 and add them back to queue
 */
vector <int> findPositions(vector <int> arr, int x) {
  // Write your code here
  queue<pair<int, int>> tempQueue;
  int originalElementsToRemove = x;
  vector<int> solution;
  for(auto i = 0; i < arr.size(); i++){
      tempQueue.push(std::make_pair(arr[i],i+1)); //First is the number, second is original index
  }

  while (x > 0)
  {
      cout << "Current Queue : " ;
      auto it = tempQueue;
      while(!it.empty()){
          cout << it.front().first << " ";
          it.pop();
      }
      cout << endl;


      pair<int,int> largestElement = make_pair(INT_MIN,INT_MIN);
      //Have another queue to temporarily store items
      queue<pair<int, int>> tempQ2;

      //Pop off queue
      for(auto i = 0; !tempQueue.empty() && i < originalElementsToRemove; i++){ //Find largest element, remove it and add it to solution
            if(tempQueue.front().first > largestElement.first){
                largestElement = tempQueue.front();
            }
            //Push to our second queue
            tempQ2.push(tempQueue.front());
            //Pop
            tempQueue.pop();
      }
      //Add largest index to solution
      if(largestElement.first != INT_MIN) solution.push_back(largestElement.second);

      //Push back onto original queue but not include largest number
      while(!tempQ2.empty()){
          if(tempQ2.front().second != largestElement.second){
              auto tempPair = tempQ2.front();
              if(tempPair.first > 0) tempPair.first--;
              tempQueue.push(tempPair);
          }
          tempQ2.pop();
      }

      x--;
  }
  
  
  return solution;
}

/**
 * @brief Plan sort the array
 * Flip the last half and that should be good 
 */
int minOverallAwkwardness(vector <int> arr) {
    if(arr.size()==0) return 0;
    if(arr.size() == 1) return arr[0];
  // Write your code here
  sort(arr.begin(),arr.end());
  //Reverse mid+1 to end
  int mid = arr.size()/2;
  if(arr.size()%2 == 0){
      reverse(arr.begin()+mid,arr.end()); //Even
  } else {
      reverse(arr.begin()+mid+1,arr.end()); //Odd number
  }

  //Count differences
  int maxDifference = arr[arr.size()-1] - arr[0];

  for(int i = 0; i < arr.size()-1; i++){
      maxDifference = std::max(maxDifference,(std::abs(arr[i] - arr[i+1])));
  }

  return maxDifference;  
}


int countPairs(string s, string t){
    int result = 0;
    int maxPairs = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == t[i]){
            result++;
        } else {
            result = 0;
            maxPairs = std::max(result,maxPairs);
        }
    }
    maxPairs = std::max(result,maxPairs);

    return maxPairs;
}

//Plan swap element and count to see pairs
//You can use a set or map to store previous values

int matchingPairs(string s, string t) {
  // Write your code here
  int maxPairs = INT_MIN;

  for(int i = 0; i < s.size(); i++){
      for(int j = 0; j < s.size(); j++){
          if(i == j) continue;
          //swap
          char tempChar_i = s[i];
          char tempChar_j = s[j];

          s[j] = tempChar_i;
          s[i] = tempChar_j;
          maxPairs = std::max(maxPairs,countPairs(s,t));

          //Swap back
          s[j] = tempChar_j;
          s[i] = tempChar_i;


      }
  }
    return maxPairs;
}
/**
 * @brief Plan
 * Find maxElement, 
 * if element is already at end of list, pop it off and continue
 * Else flip it so that it goes to the end of the list
 * Pop off the last element from the list
 * Repeat this until array is sorted
 */

int minOperationsHelper(vector<int> arr,int currentSwaps){
    if(arr.size() < 2 || is_sorted(arr.begin(),arr.end())) return currentSwaps; //Single element array is already sorted

    //Find max
    int minSwaps;
    int maxElement = INT_MIN; int maxIndex;

    for(int i =0; i<arr.size();i++){
        if(arr.at(i) >= maxElement){
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    auto maxElementIterator = max_element(arr.begin(),arr.end());
    if(maxIndex == arr.size()-1){ //Already in last position
        arr.pop_back(); //remove the last element
        minSwaps = minOperationsHelper(arr,currentSwaps);
    } else {
        //Reverse to made it to the end
        reverse(arr.begin()+maxIndex,arr.end());
        minSwaps = minOperationsHelper(arr,currentSwaps+1);
    }  

    return minSwaps;
}

int minOperations(vector <int> arr) {
  // Write your code here
  return minOperationsHelper(arr,0);
  
}

/**
 * @brief Plan if targetMoney is 0 return true; if < 0 return false;
 * if any of the denominations is a factor of targetMoney return true;
 * repeat for each remainder
 */
bool canGetExactChange(int targetMoney, vector<int>& denominations){
  // Write your code here
  if(targetMoney == 0) return true; //targetReached
  if(targetMoney < 0) return false; //targetExceeded

  
  bool result = false;
  for(int i =0; i<denominations.size(); i++){
      if(targetMoney%denominations.at(i) == 0) return true; //if any is a factor, automatic yes
      result = result | canGetExactChange(targetMoney-denominations.at(i),denominations);
  }
  
  return result;
}


string findEncryptedWord(string s) {
  // Write your code here
  string result;
  if(s.size() < 2) return s; //for empty or single char string

  int middleIndex = s.size()/2;
  if(s.size()%2 == 0) middleIndex--; //If even, take the left most character
  result.push_back(s.at(middleIndex));


  //Get rightSide
  string rightSide = "";
  if(middleIndex+1 < s.size()) rightSide = s.substr(middleIndex+1);
  //Get leftSide
  string leftSide = "";
  if(middleIndex-1 >= 0) leftSide = s.substr(0,middleIndex);
 
  return result + findEncryptedWord(leftSide) + findEncryptedWord(rightSide);
}

/**
 * @brief Plan For each side, sort and add to a set
 * return the set size
 */
int countDistinctTriangles(vector <sides> arr) {
  set<vector<int>> solution;
  
  for(auto side : arr){
      vector<int> tempTriangle;
      tempTriangle.push_back(side.a); tempTriangle.push_back(side.b); tempTriangle.push_back(side.c);
      sort(tempTriangle.begin(),tempTriangle.end());
      solution.insert(tempTriangle);
  }

    return solution.size();
  
}



//For each query
//Look for the node with int u
//Count the number of nodes in subtree with char
Node3* findNode(Node3* root, int u){
    if(root == NULL) return root;
    if(root->val == u) return root;

    Node3* result = NULL;
    for(auto child : root->children){
        if(findNode(child,u) != NULL){
            result = child;
            break;
        }
    }

    return result;
}

void countNodesEqual(Node3*root, char c, int& currentMax, string s){
    if(root == NULL) return;
    if(s.at(root->val - 1) == c) currentMax++;

    for(auto child : root->children){
        countNodesEqual(root,c,currentMax,s);
    }

}
vector<int> countOfNodes(Node3* root, vector<Query> queries, string s){
    vector<int> solution;

    for(auto query: queries){
        int currentMax = 0;
        countNodesEqual(findNode(root,query.u),query.c,currentMax,s);
        solution.push_back(currentMax);
    }

    return solution;
}

/**
 * @brief Plan, sort the array in ascending order
 * Have left and right pointers and sums of left and right
 * while left < right, 
 *      if sumLeft <= sumRight, add to leftSum; left++;
 *      else add to rightSum; right--;
 *
 *      If at any point, right value <= left value, return false;
 * 
 * Once out, if sum is equal, return true
 * 
 */
bool balancedSplitExists(vector<int>& arr){
  // Write your code here
  if(arr.size() < 2) return false;
  sort(arr.begin(),arr.end());


  int leftIndex = 0;
  int rightIndex = arr.size()-1;
  int leftMax = arr.at(leftIndex); int rightMin = arr.at(rightIndex); //Keep track of my max value
  int leftSum = 0; 
  int rightSum = 0;
  
  while(leftIndex <= rightIndex){

      if(leftSum <= rightSum){
          leftMax = std::max(leftMax,arr.at(leftIndex));
          leftSum += arr.at(leftIndex);
          cout << "Adding to left sum :" << arr.at(leftIndex) << endl;
          leftIndex++;

      } else {
          rightMin = std::min(rightMin,arr.at(rightIndex));
          rightSum += arr.at(rightIndex);
          cout << "Adding to right sum :" << arr.at(rightIndex) << endl;
          rightIndex--;
      }

      
  }
    if(leftMax >= rightMin) return false;
    cout << "left sum :" << leftSum << endl;
    cout << "right sum :" << rightSum << endl;
  return (rightSum == leftSum);
}

/**
 * @brief Plan the largest value is the leader so we can start from that number and count down 
 * Log(goal)/log(largest growth), this gets us an upper bound
 * Then start reducing until the first time you reach below goal and return days
 */
int getBillionUsersDay(vector <float> growthRates) {
  // Write your code here
  sort(growthRates.rbegin(), growthRates.rend());
  float goal = 1000000000;
  int days = 1 + (int)(log10(goal)/log10(growthRates.at(0)));
  

  while (true)
  {
      float sum = 0;

      for(auto i = 0; i < growthRates.size(); i++){
          sum = sum + pow(growthRates.at(i),days);
      }

      if(sum <= goal)break;

      days--; //reduce days
  }
  
    return days+1;
}


/**
 * @brief Plan
 * Add t to map
 * loop through s, if value is in map, remove it from map
 * if set is empty, return solution, else return -1
 */
int minLengthSubstring(string s, string t) {
  // Write your code here
  if(t.size() > s.size()) return -1;

  int solution = 0;
  bool inSearch = false;
  
  for(auto i=0; i< s.size(); i++){
      int charIndex = t.find(s[i]);    
      cout << "charIndex : " << charIndex << endl; 

      if(charIndex != -1){
          inSearch = true;
          cout << "t before : " << t << endl; 
          t.erase(charIndex,1);
          cout << "t after : " << t << endl; 
      }
      if(inSearch) solution++;

      if(t.size()==0) break;
  }
  
  
  return (t.size()==0)?-1:solution;
}


/**
 * @brief 
 * 
 * @param array_a 
 * @param array_b 
 * @return true 
 * @return false 
 */
bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
  // Write your code here
  //Sort both and check for equality
  sort(array_a.begin(),array_a.end());
  sort(array_b.begin(),array_b.end());

  return array_a == array_b;
  
}

/**
 * @brief Plan
 * Initiate a solution filled with -1
 * Initiate a sum, loop through revenue while summing
 * For milestone, if it is negative one and the sum >= milestone, change that index in the solution
 */
vector<int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  // Write your code here
  vector<int> solution (milestones.size(),-1);
  int sum = 0;

  for(int i = 0; i < revenues.size(); i++){
      sum+=revenues.at(i);

      for(int j = 0; j<milestones.size(); j++){
          if( solution.at(j) == -1 && sum >= milestones.at(j)){
              solution.at(j) = i+1;
          }
      }
  }

  
  return solution;
}

/**
 * @brief Plan 
 * temp = head
 * While temp is NOT null
 * 
 * Look for an even number -> if found, keep that start position
 * while even number -> add to a stack, temp = temp->next
 * while stack is not empty -> unload onto the start position
 * 
 * 
 * 
 *  
 */
Node2* reverse_LinkedList(Node2 *head){
    Node2 *temp = head;

    while (temp != NULL){
        if((temp->data)%2 == 0){ //If even
            stack<int> tempStack;
            Node2 *startPosition = temp;

            while (temp != NULL && (temp->data)%2 == 0) //Add the contigous values onto a stack
            {
                tempStack.push(temp->data);
                temp = temp->next;
            }
            
            //Unload values into the start position
            while(!tempStack.empty()){
                startPosition->data = tempStack.top();
                startPosition = startPosition->next; //Advance node for next update
                tempStack.pop(); //Pop off stack
            }
            

        } else {
            temp = temp->next;
        }
    }

    return head;
}

/**
 * @brief Plan for each step
 * If k == 0 return current array
 * if sorted() return currentarray
 * If smallest element is in the front, remove it or startIndex+1
 * Find smallest element with startIndex to startIndex + k
 *      swap it with the front
 *      remaining swaps is k-index
 */

vector<int> findMindArrayHelper(vector<int> arr, int k, int startIndex = 0){
    if(arr.size() == 0) return arr;
    if(k == 0) return arr;
    if(is_sorted(arr.begin(),arr.end())) return arr;

    //Find minElement
    int minElement = INT_MAX; int minIndex;

    for(int i = startIndex; i <= k && i < arr.size() ; i++){ //Dont wannt go out of bounds
        if(arr[i] < minElement){
            minElement = arr[i];
            minIndex = i;
        }
    }
    //Swap 
    int tempInt = arr[minIndex];
    arr[minIndex] = arr[startIndex];
    arr[startIndex] = tempInt;
    int remainingSwaps = minIndex - startIndex;
    

    return findMindArrayHelper(arr,remainingSwaps,startIndex+1);
}

vector<int> findMinArray(vector <int> arr, int k) {
    return findMindArrayHelper(arr,k,0);
  // Write your code here
//     if(arr.size() < 2) return arr;

//   while(k > 0){
//     //Find biggest difference
//     int elementOne = 0; int elementTwo = 0; int difference = INT_MIN;

//     for(auto i = 1; i < arr.size(); i++){ //Find largest difference
//        if((arr.at(i-1)-arr.at(i)) >= difference){
//            difference = (arr.at(i-1)-arr.at(i));
//            elementOne = i;
//            elementTwo = i-1; //Get indices
//        }             
//     }

//     //swap
//     int temp = arr.at(elementOne);
//     arr.at(elementOne) = arr.at(elementTwo);
//     arr.at(elementTwo) = temp;

//     k--;
//   }
  
//   return arr;
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

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    unordered_map<char, int> storage; //key and value

    for(int i = 0; i<s.size(); i++){
        if(storage.find(s.at(i)) == storage.end()){
            //not in map
            storage.insert(make_pair(s.at(i),1));
        } else {
            storage.at(s.at(i))++; //increment counter
        }
    }

    for(int i = 0; i<t.size(); i++){
        if(storage.find(t.at(i)) == storage.end()){
            //not in map
            return false;
        } else {
            storage.at(t.at(i))--; //increment counter
        }
    }

    //loop through map
    for(auto it = storage.begin(); it != storage.end(); it++){
        if(it->second != 0) return false;
    }

    return true;
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

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode*fast = NULL;
    if(head != NULL){
        fast = head->next;
    }

    while (slow!=NULL && fast!=NULL)
    {
        if(slow == fast) return true;
        if(fast->next != NULL){ //update fast
            if(slow == fast->next) return true;
            fast = fast->next->next;
        } else {
            fast= fast->next;
        }

        slow = slow->next; //update slow
    }
    
    return false; //they both hit null so no cycle
        
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

