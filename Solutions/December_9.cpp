#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // freqquency preq and frequency next se kr le ho jayga
        // pehle saari frquency , frequency next mien rakh lena , then you know what to do ahead
        int n = nums.size();
        if(n <3) return 0;
        const int MOD = 1e9 + 7;
        unordered_map<int,int> right,left;
        for(auto x : nums){
            right[x]++;
        }
        long long count = 0; 
        for(int i = 0 ; i < n ; i++){
            int num = nums[i];
            right[num]--;
            if(right[num] == 0){
                right.erase(num);
            }
            int ele = num*2;
            if(right.find(ele) != right.end()  && left.find(ele) != left.end()){
               long long int add = ((long long)right[ele]*left[ele])%MOD;
                count = (count + add)%MOD;
            }
            left[num]++;
        }
      return count;
    }
};