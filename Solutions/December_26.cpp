
#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX
#include <algorithm>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        // yes_forward[i] stores the count of 'Y' from index i to n-1
        // (Penalty if we close at or before index i)
        vector<int> yes_forward(n, 0);
        
        // no_backward[i] stores the count of 'N' from index 0 to i
        // (Penalty if we stay open through index i)
        vector<int> no_backward(n, 0);
        
        // 1. Calculate Suffix Sum for 'Y' (Walking Backwards)
        int count = 0;
        for(int i = n - 1; i >= 0; i--){
            if(customers[i] == 'Y'){
                count++;
            }
            yes_forward[i] = count;
        }
 
        // 2. Calculate Prefix Sum for 'N' (Walking Forwards)
        count = 0;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'N'){
                count++;
            }
            no_backward[i] = count;
        }
 
        int minPenalty = INT_MAX;
        int bestHour = 0;
        
        // 3. Evaluate every possible closing hour (0 to n)
        for(int i = 0; i <= n; i++) {
            
            // Penalty for closing at hour 'i':
            // - We miss all 'Y's from 'i' onwards.
            int y_penalty = (i < n) ? yes_forward[i] : 0;
            
            // - We suffered penalties for all 'N's strictly before 'i'.
            int n_penalty = (i > 0) ? no_backward[i-1] : 0;
            
            int total_penalty = y_penalty + n_penalty;

            // Strict inequality (<) ensures we pick the earliest hour in case of ties
            if(total_penalty < minPenalty) {
                minPenalty = total_penalty;
                bestHour = i;
            }
        }
        
        return bestHour;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case: "YYNY"
    // Hour 0: closes immediately. Misses Y,Y,Y (Cost 3)
    // Hour 1: open for Y. Misses Y,Y (Cost 2)
    // Hour 2: open for YY. Misses Y (Cost 1) -> BEST
    // Hour 3: open for YYN. Penalty for N + Misses Y (Cost 1+1=2)
    // Hour 4: open for YYNY. Penalty for N (Cost 1)
    // Note: Ties usually favor the earliest hour.
    
    string customers = "YYNY";
    
    cout << "Customer Stream: " << customers << endl;
    
    int result = sol.bestClosingTime(customers);
    
    cout << "Best closing hour: " << result << endl; // Expected: 2

    return 0;
}