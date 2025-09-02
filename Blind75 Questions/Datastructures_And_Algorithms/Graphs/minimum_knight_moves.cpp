#include <bits/stdc++.h>

using namespace std;

/*  
    Given a square chessboard of n x n size, 
    the position of the Knight and the position of a 
    target are given. We need to find out the minimum 
    steps a Knight will take to reach the target position.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Complexity

    BFS visits each cell at most once.

    For an N × N board:

    Time = O(N²)

    Space = O(N²)

    When you are looking for closest distance, use BFS
*/

// structure for storing a cell's data
struct cell {
    int x, y, dis;
    cell() : x(0), y(0), dis(0) {} 
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

// Utility method to check if (x, y) is inside the board
bool isInside(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

// Method to return the minimum steps to reach target
int minSteps(int knightPos[], int targetPos[], int n) {
    
    // x and y direction where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    // queue for storing knight's states
    queue<cell> q;

    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));

    cell t;
    int x, y;
    
    // Visit array initialized to false
    vector<vector<bool>> visit(n + 1, vector<bool>(n + 1, false));

    // visit starting position
    visit[knightPos[0]][knightPos[1]] = true;

    // loop until queue is empty
    while (!q.empty()) {
        t = q.front();
        q.pop();

        // if target is reached, return the distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;

        // explore all reachable positions
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];

            // if the position is valid and not visited, push it to queue
            if (isInside(x, y, n) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }

    // if no path found, return -1
    return -1;
}

int main() {
    int n = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minSteps(knightPos, targetPos, n);
    return 0;
}