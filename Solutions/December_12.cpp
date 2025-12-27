#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper to process a specific message event
    void applyMessageEvent(const vector<string>& event, vector<int>& mentionCount, const vector<int>& offlineTime){
        int timestamp = stoi(event[1]);
        vector<string> ids;
        stringstream ss(event[2]);
        string token;

        // Split the mention string (e.g., "id0 id1") into tokens
        while(ss >> token){
            ids.push_back(token);
        }

        // Process all IDs in the message
        for(const string& id : ids) {
            if(id == "ALL") {
                // Mention everyone
                for(int i = 0; i < mentionCount.size(); i++) {
                    mentionCount[i]++;
                }
            } else if(id == "HERE") {
                // Mention all active users
                for(int i = 0; i < mentionCount.size(); i++){
                    // User is online if they never went offline (0) or 
                    // if their offline timestamp was more than 60 units ago
                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp){
                        mentionCount[i]++;
                    }
                }
            } else {
                // Specific user mention (e.g., "id2")
                mentionCount[stoi(id.substr(2))]++; 
            }
        }
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentionCount(numberOfUsers, 0);
        vector<int> offlineTime(numberOfUsers, 0);

        // Custom Comparator: Sort by Time, then by Event Type priority
        auto lambda = [](const vector<string>& vec1, const vector<string>& vec2) {
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);

            if(t1 == t2) {
                // If times are equal, prioritize OFFLINE ('O') over MESSAGE ('M')
                // 'O' > 'M' in ASCII, so this ensures OFFLINE is processed first
                return vec1[0][1] > vec2[0][1]; 
            }
            return t1 < t2;
        };

        // Sort events to process them in chronological order
        sort(events.begin(), events.end(), lambda);

        for(const auto& event: events){
            if(event[0] == "MESSAGE") {
                applyMessageEvent(event, mentionCount, offlineTime);
            }
            else if(event[0] == "OFFLINE") {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timestamp;
            }
        }

        return mentionCount;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case: 2 Users
    int numberOfUsers = 2;
    vector<vector<string>> events = {
        {"MESSAGE", "10", "id1 id0"},
        {"OFFLINE", "11", "0"},
        {"MESSAGE", "71", "HERE"}
    };

    cout << "Processing Chat Events..." << endl;
    vector<int> results = sol.countMentions(numberOfUsers, events);

    cout << "Mention Counts:" << endl;
    for(int i = 0; i < results.size(); i++) {
        cout << "User " << i << ": " << results[i] << endl;
    }

    return 0;
}