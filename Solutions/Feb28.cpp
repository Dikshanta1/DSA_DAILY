#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    std::string toBinaryString(int n) {
    if (n == 0) return "0";
    std::string s = "";
    while (n > 0) {
        s += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    std::reverse(s.begin(), s.end());
    return s;
}
    int concatenatedBinary(int n) {
        if(n == 1) return 1;
        long long sum = 1 ;
        int mod = 1e9 + 7;
        for(int i = 2 ; i <= n ; i++){
            string str = toBinaryString(i);
            for(char ch : str){
                sum = sum << 1;
                sum = (sum | (ch-'0'))%mod;
            }
        }
        return sum%mod;
    }
};