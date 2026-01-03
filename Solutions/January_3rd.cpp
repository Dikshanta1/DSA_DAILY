#include<iostream>
using namespace std;
class Solution {
public:
    int numOfWays(int n) {
        long long abc = 6;
        long long aba = 6;
        int mod = 1e9 + 7;

        for (int i = 2; i <= n; ++i) {
            long long next_abc = (2 * abc + 2 * aba) % mod;
            long long next_aba = (2 * abc + 3 * aba) % mod;
            abc = next_abc;
            aba = next_aba;
        }

        return (abc + aba) % mod;
    }
};