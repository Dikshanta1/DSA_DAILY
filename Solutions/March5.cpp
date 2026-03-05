#include<iostream>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ans = 0;
        // case 1 : 0101 se krenge
        bool one = false;
        string str = "";
        int count = 0;
        for(int i = 0 ;i < n ; i++){
            if(one){
                str += "1";
                one = false;
            }else{
                str += "0";
                one = true;
            }
            if(s[i] != str[i]) count++;
        }
        ans = count;
        // case 2 : 1010 se krenge
        count = 0;
        bool zero = false;
        str = "";
        for(int i = 0 ;i < n ; i++){
            if(zero){
                str += "0";
                zero = false;
            }else{
                str += "1";
                zero = true;
            }
            if(s[i] != str[i]) count++;
        }
        ans = min(ans,count);
        return ans;
    }
};