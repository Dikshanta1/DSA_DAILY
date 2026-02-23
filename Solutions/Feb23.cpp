#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long total = pow(2,k);
        unordered_set<string> st;
        for(int i = k; i <= s.length() ; i++){
            string str = s.substr(i-k,k);
            if(st.count(str) == 0){
                total--;
                st.insert(str);
            }
            if(total == 0) return true;
        }
        return false;
    }
};