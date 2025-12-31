#include<iostream>
using namespace std;
class Solution {
public:
    bool canCross(int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1;
            }
        }

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            if (r == row - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark visited
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canCross(row, col, mid, cells)) {
                ans = mid;        // If possible on day 'mid', try a later day
                left = mid + 1;
            } else {
                right = mid - 1;  // If not possible, try an earlier day
            }
        }
        return ans;
    }
    
};