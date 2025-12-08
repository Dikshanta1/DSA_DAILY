#include <iostream>
#include <cmath>

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <= n; b++) {
                long long sum = (long long)a * a + (long long)b * b;
                if (sum > (long long)n * n) {
                    break; 
                }
                int c = std::sqrt(sum);
                if (c * c == sum && c <= n) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 10;
    std::cout << sol.countTriples(n) << std::endl;
    return 0;
}