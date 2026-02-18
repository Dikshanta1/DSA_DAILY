#include<iostream>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 1;
    n = n >> 1;
    while(n){
        int x = n & 1;
        if(last == x) return false;
        last = x;
        n = n>>1;
    }
    return true;
    }
};