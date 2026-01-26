#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mini = INT_MAX;
        for(int i = 1 ; i < n ; i++){
            mini = min(mini,abs(arr[i] - arr[i-1]));
        }
        vector<vector<int>> vec;
        for(int i = 1 ; i < n ; i++){
            if(abs(arr[i] - arr[i-1]) == mini){
                vec.push_back({arr[i-1],arr[i]});
            }
        }
        return vec;
    }
};