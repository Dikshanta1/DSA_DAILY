#include<iostream>
using namespace std;
class Solution {
public:
std::string toBinaryDynamic(int n) {
    if (n == 0) return "0";
    std::string result = "";
    while (n > 0) {
        result += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
int binaryToDecimal(std::string binary) {
    return std::stoi(binary, nullptr, 2); 
}
string findDifferentBinaryString(vector<string>& nums) {
    unordered_map<int,int> mp;
    int n =nums.size();
    for(auto str : nums){
        int num = binaryToDecimal(str);
        mp[num]++;
    }
    int string_size = nums[0].length();
    for(int i = 0 ; i < pow(2,n) ; i++){
        if(mp[i] == 0){
            string str = toBinaryDynamic(i);
            if(str.length() != string_size){
                int len = string_size - str.length();
                for(int l = 0 ; l < len ; l++){
                    str = "0" + str;
                }
            }
            return str;
        }
    }
    return "";        
}
};
