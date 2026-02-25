#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vec;
        for(auto x : arr){
            int count = Bits(x);
            vec.push_back({count,x});
        }
        sort(vec.begin(),vec.end());
        vector<int> result;
        for(auto x : vec){
            result.push_back(x.second);
        }
        return result;
    }
    int Bits(int num){
        int count = 0 ;
        while(num > 0){
            if(num & 1){
                count++;
            }
            num = num>>1;
        }
        return count;
    }
};