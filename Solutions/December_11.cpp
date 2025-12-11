#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> yToMinMaxX;
        unordered_map<int, pair<int,int>> xToMinMaxY;

        for (const auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            if (yToMinMaxX.find(y) == yToMinMaxX.end()) 
                yToMinMaxX[y] = {INT_MAX, INT_MIN};

            if (xToMinMaxY.find(x) == xToMinMaxY.end()) 
                xToMinMaxY[x] = {INT_MAX, INT_MIN};

            yToMinMaxX[y].first  = min(yToMinMaxX[y].first, x);
            yToMinMaxX[y].second = max(yToMinMaxX[y].second, x);

            xToMinMaxY[x].first  = min(xToMinMaxY[x].first, y);
            xToMinMaxY[x].second = max(xToMinMaxY[x].second, y);
        }

        int result = 0;

        for (const auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            auto &xr = yToMinMaxX[y];
            auto &yr = xToMinMaxY[x];

            if (xr.first < x && x < xr.second &&
                yr.first < y && y < yr.second) {
                result++;
            }
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<vector<int>> buildings = {
        {2, 1}, {2, 3},
        {1, 2}, {3, 2},
        {2, 2}
    };

    int n = buildings.size();
    cout << sol.countCoveredBuildings(n, buildings) << endl;

    return 0;
}