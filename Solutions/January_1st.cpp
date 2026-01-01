#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1 ;
        for(int i = n -1 ; i>= 0 ; i--){
            int d = digits[i];
            if(d + carry ==10){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i] = digits[i] + carry;
                carry = 0;
            }
        }
        if(carry == 1){
            vector<int> ans(n+1,1);
            for(int i = 1 ; i <= n ; i++){
                ans[i] = digits[i-1];
            }
            return ans;
        }
        return digits;
    }
};