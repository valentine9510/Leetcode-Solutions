/**
 * @file task_schedular.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.
    ​Return the minimum number of intervals required to complete all tasks.

    Example 1:

    Input: tasks = ["A","A","A","B","B","B"], n = 2

    Output: 8

    Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
    After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

    Example 2:
    Input: tasks = ["A","C","A","B","D","B"], n = 1

    Output: 6
    Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
    With a cooling interval of 1, you can repeat a task after just one other task.

    Example 3:
    Input: tasks = ["A","A","A", "B","B","B"], n = 3
    Output: 10

    Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

    There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

    
*/
#include <bits/stdc++.h>

using namespace std;

/*
    Solution Explanation:
    Step 1: Frequency Count of Tasks
    The first step is to calculate how often each task appears. We store this information in a frequency array of size 26 (one for each letter).

    vector<int> freq(26, 0);
    for (char task : tasks) {
        freq[task - 'A']++;
    }
    Example: If tasks = ['A', 'A', 'A', 'B', 'B', 'C'], then the frequency array will look like this: [3, 2, 1, 0, 0, ..., 0] where 3 represents 'A', 2 represents 'B', and 1 represents 'C'.


    Step 2: Max-Heap (Priority Queue)
    We use a max-heap (implemented using priority_queue in C++) to always work on the task with the highest remaining frequency.

    priority_queue<int> pq;
    for (int count : freq) {
        if (count > 0) {
            pq.push(count);
        }
    }
    Explanation: The heap helps us to always schedule the task that has the most occurrences left. We push all non-zero frequencies into the heap.


    Step 3: Simulating CPU Cycles
    Now, we simulate the CPU cycles. The idea is to process up to n+1 tasks at a time (because we can process n other tasks between two occurrences of the same task).


    int cycles = 0;
    while (!pq.empty()) {
        vector<int> temp;
        for (int i = 0; i <= n; ++i) {
            if (!pq.empty()) {
                temp.push_back(pq.top());
                pq.pop();
            }
        }
    Explanation: We pull out up to n+1 tasks from the heap. These represent the tasks we're going to process in the next n+1 cycles.

    Step 4: Process the Tasks
    We now process the tasks and push them back into the heap if they still have occurrences left after one cycle.

    for (int count : temp) {
        if (--count > 0) {
            pq.push(count);
        }
    }
    Explanation: We decrement the count of each task. If any task still has more instances left after this round, we push it back into the heap.

    Step 5: Update the Number of Cycles
    Finally, we update the total number of cycles taken. If the heap is empty after processing, then we've finished scheduling all tasks, and the number of cycles taken will be the number of tasks processed (without any idle time). If the heap isn't empty, we have to account for the full n+1 cycles.

    cycles += pq.empty() ? temp.size() : n + 1;
    Explanation: If the heap is empty, it means we’ve processed all the tasks in this round, so we only add the exact number of tasks processed (temp.size()). Otherwise, we add n+1 to account for the full cycle, which includes any idle time. uppdate the scheduling
    }
*/


#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
    Trick is to know that you can always process n+1 cycles for sure

    Get a frequency map

    Put those counts onto a max heap, so we always catch the most popular tasks

    Get the n+1 tasks from the max heap

    Put back updated values
        Only update those who have a value > 0

    Update cycle amount
        If queue is empty
            Update only cycles that you used
        If is not empty
            Update with n+1
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Create a frequency array to count occurrences of each task
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Create a max heap (priority queue) to store task frequencies in descending order
        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) {
                pq.push(count);  // Push only non-zero frequencies
            }
        }

        int cycles = 0;  // Initialize cycle count

        // Step 3: Simulate the scheduling process
        while (!pq.empty()) {
            // Temporary list to hold tasks that are being processed in the current cycle
            vector<int> temp;

            // Step 4: Process up to n+1 tasks in one cycle
            for (int i = 0; i <= n; ++i) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());  // Get the most frequent task
                    pq.pop();  // Remove it from the heap
                }
            }

            // Step 5: After processing, decrease the count of each task
            for (int count : temp) {
                count--;
                if (count > 0) {
                    pq.push(count);  // If tasks are still remaining, push them back into the heap
                }
            }

            // Step 6: Update the cycle count
            if (pq.empty()) {
                // If the heap is empty, add the number of tasks processed in this cycle
                cycles += temp.size();
            } else {
                // If the heap is not empty, we need to add the full cycle of n+1 units
                cycles += n + 1;
            }
        }

        return cycles;  // Return the total number of cycles
    }
};

