#include <iostream>

class Solution {
public:
    int countOdds(int low, int high) {
        int odd = 0;
        if(low % 2 == 1 && high % 2 == 1){
            int a = low;
            int n = (high - a) / 2 + 1;
            return n;
        }
        else if(low % 2 == 1 && high % 2 == 0){
            high = high - 1;
            if(high >= low){
                int n = (high - low) / 2 + 1;
                return n;
            }
            return 0;
        }
        else if(low % 2 == 0 && high % 2 == 0){
            low++;
            high--;
            if(low <= high){
                int n = (high - low) / 2 + 1;
                return n;
            }
            return 0;
        }
        else{
            low++;
            if(low <= high){
                int n = (high - low) / 2 + 1;
                return n;
            }
            return 0;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    std::cout << sol.countOdds(3, 7) << std::endl;
    std::cout << sol.countOdds(8, 10) << std::endl;
    return 0;
}