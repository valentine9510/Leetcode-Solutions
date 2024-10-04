/**
 * @file IBM.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Question 1
1. Question 1
For a number N, a goodArray is the smallest possible array that consists of only powers of two (2^0, 2^1, ... ,2^k) such that the sum of all the numbers in the array is equal to N.

For each query that consists of three integers l, r, and m, find out the product of elements goodArray[l] through goodArray[r] modulo m when goodArray is sorted in non-decreasing order.

Example
For N = 26, queries = [[1, 2, 1009], [3, 3, 5]]

goodArray when sorted is [2,8,16].

For query l = 1, r = 2, m = 1009, ans = goodArray[1] * goodArray[2] = (2*8) modulo 1009 = 16.
For query / = 3, r = 3, m = 5, ans = goodArray = (16) modulo 5 = 1.
The answer is [16, 1].


Function Description
Complete the function getQueryResults in the editor below.
getQueryResults has the following parameters:

long N: the integer N
int queries[q][3]: a 2D array of queries, each with 3 elements l, r, and m.

Return
int answer[q]: the answers to the queries

Constraints
• 1≤ N ≤ 10^18
• 1 ≤ q≤10^5
• 1≤m≤10^5
•1 ≤1 ≤ r ≤ |goodArray|, where |goodArray| denotes the length of the array

Sample Input For Custom Testing
N = 6
q=3
q[] size = 3
queries = [[1,2,4], [2,2,8], [1,1,4]]

Sample Output
sorted goodArray is [2, 4]

Explanation
The sorted goodArray is [2, 4]. This is the smallest possible array in which every element is a power of 2, and the elements sum up to N = 6.

Query 1: l = 1, r = 2, m = 4; ans = goodArray[1]* goodArray[2] = (2*4) modulo 4 = 0.
Query 2: l = 2, r = 2, m = 8; ans = goodArray[2] = 4 modulo 8 = 4. 
Query 3: 1 = 1, r = 1, m = 4; ans = goodArray[1] = 2 modulo 4 = 2.



 * Question 2
You are given a log file with a list of GET requests delimited with double quotes and spaces.
A sample and the structure of the text file containing the log entries are given below.
Sample log record:
unicomp6.unicomp.net - - [01/Jul/1995:00:00:06 -0400] "GET /shuttle/countdown/ HTTP/1.0" 200 3985

Log file structure:
Hostname | - | - | Timestamp |Request | HTTP Response Code | Bytes
One examples is 
unicomp6.unicomp.net | -|-| [01/Jul/1995:00:00:06-0400] | "GET /shuttle/countdown/ HTTP/1.0" | 200 | 3985

Given a filename that denotes a text file in the current working directory. Create an output file with the name "bytes_" prefixed to the filename (bytes_filename), which stores the information about large responses.

Example: filename = "hosts_access_log_00.txt"; process the records in hosts_access_log_00.txt and create an output file named bytes_hosts_access_log_00.txt.

Write the following to the output file:
1. The first line must contain the number of requests that have more than 5000 bytes sent in their response.
2. The second line must contain the total sum of bytes sent by all responses sending more than 5000 bytes.

Note:
The output file has to be written to the current directory.
Constraints
• It is guaranteed that the total number of bytes sent by all large responses does not exceed 1012.
• The log file contains no more than 2 x 105 records.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<long long> constructGoodArray(long long N) {
    vector<long long> goodArray;
    for (int i = 0; i < 64; ++i) {
        if (N & (1LL << i)) {
            goodArray.push_back(1LL << i);
        }
    }
    return goodArray;
}

vector<int> getQueryResults(long long N, const vector<vector<int>>& queries) {
    vector<long long> goodArray = constructGoodArray(N);
    vector<int> answers;

    for (const auto& query : queries) {
        int l = query[0] - 1;  // Adjusting index to 0-based
        int r = query[1] - 1;
        int m = query[2];
        long long product = 1;

        for (int i = l; i <= r; ++i) {
            product = (product * goodArray[i]) % m;
        }

        answers.push_back(static_cast<int>(product));
    }

    return answers;
}

int main() {
    long long N;
    int q;
    cin >> N >> q;

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> results = getQueryResults(N, queries);
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}

/** Question 2 Solution */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main2() {
    std::string filename = "hosts_access_log_00.txt";
    std::ifstream inFile(filename);
    std::string outputFile = "bytes_" + filename;
    std::ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    int count = 0;
    long long totalBytes = 0;

    while (getline(inFile, line)) {
        std::istringstream iss(line);
        std::string segment;
        std::vector<std::string> seglist;

        while (getline(iss, segment, ' ')) { //place whole string into an array
            seglist.push_back(segment);
        }

        // Assuming the bytes are always the last element
        long long bytes = std::stoll(seglist.back());
        if (bytes > 5000) {
            count++;
            totalBytes += bytes;
        }
    }

    outFile << count << std::endl;
    outFile << totalBytes << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}

