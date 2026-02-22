#include<iostream>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        string str = "";
        while(n){
            int x = n%2;
            n/= 2;
            str += to_string(x);
            
        }
        int distance = 0;
        int first = -1 ;
        for(int i = 0 ; i < str.length() ; i++){
            if(str[i] == '1'){
                    if(first == -1) first = i;
                    else{
                    distance = max(distance,i-first);
                    first = i;
                    }
            }
        }
        return distance;
    }
};