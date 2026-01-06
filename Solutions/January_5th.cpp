#include<iostream>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0 ;
        int negative_count = 0 ;
        int mini_absolute = INT_MAX;
        bool zero = false;
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int num = matrix[i][j];
                sum += llabs(num);
                if(num == 0) zero = true;
                if(num < 0) negative_count++;
                mini_absolute = min(mini_absolute,abs(num));
            }
        }
        if(negative_count % 2 == 1 && !zero){
            sum -= 2LL * mini_absolute;
        }
        return sum;
    }
};