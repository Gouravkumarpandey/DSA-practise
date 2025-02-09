#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Handle bottom-left triangle (including middle diagonal)
        for(int i = 0; i < n; i++) {
            vector<int> diagonal;
            int row = i, col = 0;
            // Collect diagonal elements
            while(row < n && col < n) {
                diagonal.push_back(grid[row][col]);
                row++; col++;
            }
            // Sort in descending order
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            // Put back the sorted elements
            row = i; col = 0;
            int idx = 0;
            while(row < n && col < n) {
                grid[row][col] = diagonal[idx++];
                row++; col++;
            }
        }
        
        // Handle top-right triangle
        for(int j = 1; j < n; j++) {
            vector<int> diagonal;
            int row = 0, col = j;
            // Collect diagonal elements
            while(row < n && col < n) {
                diagonal.push_back(grid[row][col]);
                row++; col++;
            }
            // Sort in ascending order
            sort(diagonal.begin(), diagonal.end());
            // Put back the sorted elements
            row = 0; col = j;
            int idx = 0;
            while(row < n && col < n) {
                grid[row][col] = diagonal[idx++];
                row++; col++;
            }
        }
        
        return grid;
    }
};

// Test function
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};
    
    cout << "Original Matrix:" << endl;
    for(const auto& row : grid) {
        for(int num : row) cout << num << " ";
        cout << endl;
    }
    
    auto result = sol.diagonalSort(grid);
    
    cout << "\nSorted Matrix:" << endl;
    for(const auto& row : result) {
        for(int num : row) cout << num << " ";
        cout << endl;
    }
    
    return 0;
}