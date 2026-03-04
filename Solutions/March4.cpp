#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        unordered_map<int,int> r;
        unordered_map<int,int> c;
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                if(mat[row][col] == 1){
                    r[row]++;
                    c[col]++;
                }
            }
        }
        int count = 0;
         for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                if(mat[row][col] == 1){
                    if(r[row] == 1 && c[col] == 1){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};