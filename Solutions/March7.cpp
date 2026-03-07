#include<iostream>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if(n == 1) return 0;
        string str1 = "";
        string str2 = "";
        s += s;

        for(int i = 0 ; i < 2*n ; i++){
            str1 +=  (i%2) ? '0' : '1';
            str2 += (i%2) ? '1' : '0';
        }
        
        vector<int> vec1(2*n,0);
        vector<int> vec2(2*n, 0);
        int count = 0;

        for(int i = 0 ; i < 2*n ; i++){
            if(s[i] != str1[i]){
                count++;
            }
            vec1[i] = count;
        }
        
        count = 0;
        for(int i = 0 ; i < 2*n ; i++){
            if(s[i] != str2[i]){
                count++;
            }
            vec2[i] = count;
        }
        
        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int flips1 = vec1[i+n-1] - (i > 0 ? vec1[i-1] : 0);
            mini = min(mini, flips1);
        }
        for(int i = 0 ; i < n ; i++){
            int flips2 = vec2[i+n-1] - (i > 0 ? vec2[i-1] : 0);
            mini = min(mini, flips2);
        }
        
        return mini;
    }
};