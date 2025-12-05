#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;

        vector<int> prefix_sum(size, 0);

        prefix_sum[0] = nums[0];
        for (int i = 1; i < size; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        int count = 0;
        for (int i = 0; i < size - 1; i++) {
            int left_sum = prefix_sum[i];
            int right_sum = prefix_sum[size - 1] - prefix_sum[i];
            if ((left_sum - right_sum) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.countPartitions(nums) << endl;

    return 0;
}