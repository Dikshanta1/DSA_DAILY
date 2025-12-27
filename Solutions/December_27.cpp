
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For LLONG_MAX

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        // 1. Sort meetings by start time to process chronologically
        sort(begin(meetings), end(meetings)); 

        vector<int> roomsUsedCount(n, 0);       // Count of meetings per room
        vector<long long> lastAvailableAt(n, 0); // Timestamp when room becomes free
        
        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];
            bool found = false;

            long long EarlyEndRoomTime = LLONG_MAX;
            int EarlyEndRoom = 0;

            // 2. Try to find the first available meeting room
            // Iterating 0 to n ensures we pick the lowest index if multiple are free
            for(int room = 0; room < n; room++) {
                if(lastAvailableAt[room] <= start) {
                    found = true;
                    lastAvailableAt[room] = end; // Update availability to current meeting's end
                    roomsUsedCount[room]++;
                    break; 
                }

                // Track the room that finishes earliest (for case where all are busy)
                if(lastAvailableAt[room] < EarlyEndRoomTime) {
                    EarlyEndRoom = room;
                    EarlyEndRoomTime = lastAvailableAt[room];
                }
            }

            // 3. If no room is free, delay the meeting
            if(!found) {
                // The room stays occupied for the duration of this meeting,
                // added to its PREVIOUS finish time (not the current time)
                lastAvailableAt[EarlyEndRoom] += (end - start);
                roomsUsedCount[EarlyEndRoom]++;
            }
        }

        // 4. Find the room with maximum usage (lowest index breaks ties)
        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case: 2 Rooms, 4 Meetings
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};

    cout << "Processing Meetings for " << n << " rooms..." << endl;
    
    int result = sol.mostBooked(n, meetings);
    
    cout << "The room booked the most is: Room " << result << endl;
    // Explanation:
    // Room 0: [0,10]
    // Room 1: [1,5]
    // Room 1 finishes at 5. Next meeting [2,7] is delayed -> starts at 5, ends at 5+(7-2)=10. Room 1: [5,10]
    // Room 1 finishes at 10. Next meeting [3,4] is delayed -> starts at 10...
    
    return 0;
}