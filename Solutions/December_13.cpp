#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to check if a string is alphanumeric or underscores
    bool isvalidcode(const string &code){
        if(code.empty()) return false;
        for(char ch : code){
            if(!isalnum(ch) && ch != '_') return false;
        }
        return true;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessline, vector<bool>& isActive) {
        int n = code.size();
        
        // Allowed business lines
        unordered_set<string> validline = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };
        
        // Map to group codes by business line
        map<string, vector<string>> categorizedCodes;
        
        for(int i = 0; i < n; i++){
            // 1. Check valid characters
            if(!isvalidcode(code[i])) continue;
            
            // 2. Check valid business line
            if(validline.find(businessline[i]) == validline.end()) continue;
            
            // 3. Check if active
            if(!isActive[i]) continue;
            
            categorizedCodes[businessline[i]].push_back(code[i]);
        }
        
        // Defined order for output
        vector<string> blorder = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<string> result;
        for(const string &line : blorder){
            if (categorizedCodes.find(line) != categorizedCodes.end()) {
                auto &codes = categorizedCodes[line];
                // Sort codes alphabetically within the category
                sort(codes.begin(), codes.end());
                result.insert(result.end(), codes.begin(), codes.end());
            }
        }
        return result;
    }
};

// Main function to demonstrate the solution
int main() {
    Solution sol;
    
    // Test Data
    vector<string> codes = {"100_OFF", "INVALID#", "FREESHIP", "LUNCH_20", "MEDS_10"};
    vector<string> businesses = {"electronics", "grocery", "electronics", "restaurant", "pharmacy"};
    vector<bool> active = {true, true, false, true, true};

    cout << "Processing Coupons..." << endl;
    
    vector<string> validCoupons = sol.validateCoupons(codes, businesses, active);

    cout << "Valid Sorted Coupons: " << endl;
    for(const string& c : validCoupons) {
        cout << "- " << c << endl;
    }

    return 0;
}