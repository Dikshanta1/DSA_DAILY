#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = 1e9 + 7;
        
        vector<int> dp(n + 1, 0);
        vector<int> prefix(n + 2, 0);
        
        dp[0] = 1;
        prefix[1] = 1;
        
        deque<int> max_d, min_d;
        int l = 0;
        
        for (int r = 0; r < n; ++r) {
            while (!max_d.empty() && nums[max_d.back()] <= nums[r]) max_d.pop_back();
            max_d.push_back(r);
            
            while (!min_d.empty() && nums[min_d.back()] >= nums[r]) min_d.pop_back();
            min_d.push_back(r);
            
            while (nums[max_d.front()] - nums[min_d.front()] > k) {
                if (max_d.front() == l) max_d.pop_front();
                if (min_d.front() == l) min_d.pop_front();
                l++;
            }
            
            long long ways = (prefix[r + 1] - prefix[l] + mod) % mod;
            dp[r + 1] = ways;
            prefix[r + 2] = (prefix[r + 1] + ways) % mod;
        }
        
        return dp[n];
    }
};