#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        
        // 1. Use a Max Heap (Priority Queue) to always access the largest current happiness
        priority_queue<int> pq;
        for(int x : happiness){
            pq.push(x);
        }
        
        int n = happiness.size();
        // 2. Decrement factor: starts at 0 and decreases by 1 for each child picked
        int dec = 0;
        
        // 3. Pick the top k children
        for(int i = 0 ; i < k && i < n ; i++){
            int currentVal = pq.top();
            pq.pop();
            
            // Calculate effective happiness (cannot be negative)
            // effective = original_value - turns_waited
            // Note: dec is negative in your logic (0, -1, -2), so we add it.
            sum += max(0, currentVal + dec);
            
            dec--; // Increase the penalty for the next child
        }
        return sum;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case
    vector<int> happiness = {1, 2, 3};
    int k = 2;

    cout << "Happiness Values: {1, 2, 3}, k: " << k << endl;
    
    long long result = sol.maximumHappinessSum(happiness, k);
    
    cout << "Maximum Happiness Sum: " << result << endl; 
    // Logic: Pick 3 (val=3-0=3), then Pick 2 (val=2-1=1). Total = 4.

    return 0;
}