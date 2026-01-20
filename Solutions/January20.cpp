#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> vec;
        for(auto x : nums){
            bool found = false;
            for(int i = 0 ; i < x ; i++){
                if((i | i+1) == x){
                    found = true;
                    vec.push_back(i);
                    break;
                }
            }
            if(!found) vec.push_back(-1);
        }
        return vec;
    }
};