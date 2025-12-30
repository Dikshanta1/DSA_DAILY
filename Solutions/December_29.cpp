#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
    int cols = grid[0].size();
    if(rows < 3 || cols < 3) return 0;
    
    int count = 0;
    for(int row = 1; row < rows - 1; row++) {
        for(int col = 1; col < cols - 1; col++) {
            
            bool isDistinct = true;
            vector<int> check(10, 0); 
            for(int i = row - 1; i <= row + 1; i++) {
                for(int j = col - 1; j <= col + 1; j++) {
                    int val = grid[i][j];
                    if(val < 1 || val > 9 || check[val] > 0) {
                        isDistinct = false;
                        break;
                    }
                    check[val]++;
                }
            }
            if(!isDistinct) continue;

            // first row sum
            int first_row = grid[row -1][col-1] + grid[row -1][col] + grid[row -1][col +1];
            // second row sum
            int second_row = grid[row][col-1] + grid[row][col] + grid[row][col +1];
            // third row sum
            int third_row = grid[row +1][col-1] + grid[row +1][col] + grid[row +1][col +1];

            // first col sum
            int first_col = grid[row -1][col -1] + grid[row][col -1] + grid[row+1][col-1];
            // second col sum
            int second_col = grid[row -1][col] + grid[row][col] + grid[row+1][col];
            // third col sum
            int third_col = grid[row-1][col + 1] + grid[row][col +1] + grid[row +1][col+1];

            // 1st diagonal sum
            int first_dia = grid[row -1][col -1] + grid[row][col] + grid[row +1][col +1];
            // 2nd diagonal sum
            int second_dia = grid[row-1][col + 1] + grid[row][col] + grid[row +1][col-1];
            
            unordered_map<int,int> mp;
            mp[first_row]++;
            mp[second_row]++;
            mp[third_row]++;
            mp[first_col]++;
            mp[second_col]++;
            mp[third_col]++;
            mp[first_dia]++;
            mp[second_dia]++;
            
            if(mp.size() == 1) count++;
        }
    }
    return count;
    }
};