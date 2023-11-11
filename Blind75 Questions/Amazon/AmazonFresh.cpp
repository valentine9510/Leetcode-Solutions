/******************************************************************
 * Amazon Challenge Solution
 * main.cpp
 * 
 * 
 * 
 * ***************************************************************/
#include <iostream>
#include <vector>




using namespace std;

/* Functions */
int FindDistance(vector<vector<int>>&);
bool FindDistanceHelper(int currentRow, int currentColumn, int currentDistance, vector<vector<int>>& grid, vector<vector<bool>> visited);

template <typename T>
void printVector(vector<T> inputVector){
    cout << "Input vector [";
    for(auto i : inputVector){
        cout << i << " ";
    }
    cout << "]" << endl;
}

static int finalDistance = -1;



int main() {
    int numRows = 5, numColumns = 4;
    vector<vector<int>> grid0 = { { 1, 1, 1, 1 }, 
                                  { 0, 1, 1, 1 }, 
                                  { 0, 1, 0, 1 }, 
                                  { 1, 1, 9, 1 }, 
                                  { 0, 0, 1, 1 } };   

    vector<vector<int>> grid1 = { { 1, 0, 0 }, 
                                  { 1, 0, 0 }, 
                                  { 1, 9, 0 }};  

    vector<vector<int>> grid2 = { { 1, 0, 0 }, 
                                  { 1, 0, 0 }, 
                                  { 1, 0, 0 }}; 
                                  

    vector<vector<int>> currentGrid = grid2;
    cout << "Welcome" << endl;

    vector<vector<bool>> visited (currentGrid.size(), vector<bool> (currentGrid.at(0).size(),false));

    FindDistanceHelper(0,0,0,currentGrid,visited);
    
    cout << "Distance found is : " << finalDistance;

    return 0;
}


int FindDistance(vector<vector<int>> &grid){
    finalDistance = 0;

    vector<vector<bool>> visited (grid.size(), vector<bool> (grid.at(0).size(),false));

    int distanceMoved = 0;

    if(FindDistanceHelper(0,0,distanceMoved,grid,visited)){
        return finalDistance;
    }

    return -1;
}

bool FindDistanceHelper(int currentRow, int currentColumn, int currentDistance, vector<vector<int>>& grid, vector<vector<bool>> visited){
    int rows = grid.size();
    int columns = grid.at(0).size();

    //cout << "Location [" << currentRow << "," << currentColumn << "]" << endl;

    //Check bounds
    if ((currentRow < 0) || (currentColumn < 0) || (currentRow >= grid.size()) || (currentColumn >= grid.at(0).size())){
        return false;
    }

    //Check visited or 0
    if(grid.at(currentRow).at(currentColumn) == 0 || visited.at(currentRow).at(currentColumn) == true){
        return false;
    }

    //Check if cell is 9
    if(grid.at(currentRow).at(currentColumn) == 9){
        cout << "Landed on a 9, current distance is :" << currentDistance << endl;
        cout << "-------------------------------------------\n\n";
        if(finalDistance == -1){
            finalDistance = currentDistance;
        } else {
            finalDistance = std::min(finalDistance,currentDistance);
        }
        return true;
    }

    //Cell is one
    if(grid.at(currentRow).at(currentColumn) == 1){
        cout << "Location [" << currentRow << "," << currentColumn << "]" << endl;
        visited.at(currentRow).at(currentColumn) = true;
        currentDistance++;
    }

    //Go down
    bool downSearch = FindDistanceHelper(currentRow+1,currentColumn, currentDistance,grid,visited);
    //Go right
    bool rightSearch = FindDistanceHelper(currentRow,currentColumn+1, currentDistance,grid,visited);
    //Go left
    bool leftSearch = FindDistanceHelper(currentRow,currentColumn-1, currentDistance,grid,visited);
    //Go up
    bool upSearch = FindDistanceHelper(currentRow-1,currentColumn, currentDistance,grid,visited);

    return (downSearch || rightSearch || leftSearch || upSearch);
}

