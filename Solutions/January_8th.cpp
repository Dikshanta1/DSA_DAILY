/**
 * Problem: Max Dot Product of Two Subsequences
 * Platform: LeetCode (Problem 1458)
 * Language: C++
 * Approach: Dynamic Programming (Memoization / Top-Down)
 * * Description:
 * Given two arrays nums1 and nums2, return the maximum dot product between 
 * non-empty subsequences of nums1 and nums2 with the same length.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int m, n;
    // Memoization table: 501 is based on constraint limits
    int t[501][501];
    
    // Sentinel value for unvisited states
    const int UNVISITED = -1e9; 
    
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        // Base Case: If we run out of elements in either array
        if(i == m || j == n) {
            // Return a large negative number to indicate invalid path.
            // We don't return 0 because the result can be negative 
            // (e.g., {-1, -1} and {1, 1} -> result -1).
            return -100000000; 
        }
        
        // Return cached result if already computed
        if(t[i][j] != UNVISITED)
            return t[i][j];
        
        int val = nums1[i] * nums2[j];
        
        // Option 1: Take both current elements (i and j), add to result of remaining
        int take_i_j = solve(nums1, nums2, i+1, j+1) + val;
        
        // Option 2: Skip current element of nums1, move to next
        int skip_i = solve(nums1, nums2, i+1, j);
        
        // Option 3: Skip current element of nums2, move to next
        int skip_j = solve(nums1, nums2, i, j+1);
        
        // We take the max of:
        // 1. Just the current product 'val' (starts a new subsequence here)
        // 2. Current product + result of remainder
        // 3. Skipping i
        // 4. Skipping j
        return t[i][j] = max({val, take_i_j, skip_i, skip_j});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        
        // Initialize DP table
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = UNVISITED;
            }
        }
        
        return solve(nums1, nums2, 0, 0);
    }
};

// Driver code for testing
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    cout << "Test Case 1: " << sol.maxDotProduct(nums1, nums2) << endl; 
    // Expected: 18 (2*3 + -2*-6 = 6 + 12 = 18)

    // Test Case 2
    vector<int> n3 = {3, -2};
    vector<int> n4 = {2, -6, 7};
    cout << "Test Case 2: " << sol.maxDotProduct(n3, n4) << endl; 
    // Expected: 21 (3*7 = 21)

    // Test Case 3
    vector<int> n5 = {-1, -1};
    vector<int> n6 = {1, 1};
    cout << "Test Case 3: " << sol.maxDotProduct(n5, n6) << endl; 
    // Expected: -1

    return 0;
}