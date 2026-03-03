#include<iostream>
using namespace std;
class Solution {
public:
    string inverse(string str){
        for(char &ch : str){
            if(ch == '0') ch = '1';
            else ch = '0';
        }
        return str;
    }
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        string old = "0";
        string newone = "";
        for(int i = 2 ; i <= n ; i++){
            string str = inverse(old);
            reverse(str.begin(),str.end());
            newone = old + "1" + str;
            old = newone;
        }
        return old[k-1];
    }
};