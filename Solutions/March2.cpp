#include<iostream>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> trailing_zeros(n,0);
        for(int j = 0 ; j < n ; j++){
            int zeros = 0;
            for(int i = n -1 ; i>= 0 ; i--){
                if(grid[j][i] == 0) zeros++;
                else break;
            }
            trailing_zeros[j] = zeros;
        }
        int steps = 0;
        for(int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;
            while(j < n && trailing_zeros[j] < need) {
                j++;
            }
            if(j == n) {
                return -1;
            }
            steps += j-i;
            while(j > i) {
                swap(trailing_zeros[j], trailing_zeros[j-1]);
                j--;
            }
        }
        return steps;
    }
};          