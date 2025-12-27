
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // 1. Calculate the total number of apples needed to be stored
        int total_apples = 0;
        for(int x : apple){
            total_apples += x;
        }

        // 2. Sort box capacities in descending order (Greedy approach)
        // We want to use the largest boxes first to minimize the count.
        sort(capacity.rbegin(), capacity.rend());

        int current_capacity = 0;
        int boxes_used = 0;
        int n = capacity.size();

        // 3. Pick boxes until we fit all apples
        while(total_apples > current_capacity && boxes_used < n){
            current_capacity += capacity[boxes_used];
            boxes_used++;
        }
        
        return boxes_used;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1
    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};

    cout << "Test Case 1:" << endl;
    cout << "Apples: {1, 3, 2}, Capacity: {4, 3, 1, 5, 2}" << endl;
    
    int result = sol.minimumBoxes(apple, capacity);
    cout << "Minimum boxes needed: " << result << endl; // Expected: 2 (using boxes 5 and 4 or 5 and 3)

    return 0;
}