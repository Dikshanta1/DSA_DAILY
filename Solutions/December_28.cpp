/*
 * Problem: LeetCode 1351 - Count Negative Numbers in a Sorted Matrix
 * Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
 * * Approach: Brute Force Iteration
 * Time Complexity: O(m * n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] < 0) count++;
            }
        }
        return count;
    }
};

int main() {
    // Test Case: Creating a sample grid
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    // Instantiate the solution class
    Solution sol;
    
    // Call the function
    int result = sol.countNegatives(grid);

    // Print the output
    cout << "Input Grid:" << endl;
    for(const auto& row : grid) {
        for(int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
    
    cout << "\nNumber of negative numbers: " << result << endl;

    return 0;
}