#include<iostream>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 3 )return false;
        int p = 0 ;
        int q = n -1;
        // increasing order check kr liya from start
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i-1]){
                p = i;
            }else{
                break;
            }
        }
        // increasing order check from end
        for(int i = n-2; i > 1 ; i--){
            if(nums[i] < nums[i+1]){
                q = i;
            }else{
                break;
            }
        }
        
        // decreasing order ka check krte h ab
        int mid = p+1;
        for(int i = p ; i < q ; i++){
            if(nums[i] < nums[i+1])return false;
            mid = i;
        }
        if(q <= p) return false;
        if(p == 0 || q == n-1) return false;
        if(nums[q] == nums[q-1])return false;
        if(nums[p]== nums[p+1]) return false;

        return true;
    }
};