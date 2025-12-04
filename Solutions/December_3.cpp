#include<iostream>
#include<vector>
using namespace std;
#include<map>
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& pts) {
    int n = pts.size();
    if (n < 2) return 0;

    unordered_map<float, vector<float>> slopeToIntercepts;
    unordered_map<long long, vector<float>> midMap;

    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int x1 = pts[i][0], y1 = pts[i][1];
            int x2 = pts[j][0], y2 = pts[j][1];

            int dx = x2 - x1, dy = y2 - y1;

            float slope, c;

            // Vertical line handling
            if (dx == 0) {
                slope = 1e9;      // represent infinite slope
                c     = x1;       // x-intercept
            } else {
                slope = (float)dy / dx;
                c     = (float)(y1 * dx - x1 * dy) / dx;
            }

            long long midKey = (long long)(x1 + x2) * 10000LL + (y1 + y2);

            slopeToIntercepts[slope].push_back(c);
            midMap[midKey].push_back(slope);
        }
    }

    // Count pairs of parallel lines (possible trapezoid bases)
    for (auto &p : slopeToIntercepts) {
        if (p.second.size() <= 1) continue;

        map<float, int> freq;
        for (float c : p.second) freq[c]++;

        int prev = 0;
        for (auto &q : freq) {
            total += q.second * prev;
            prev  += q.second;
        }
    }

    // Remove overcounting (same midpoint lines)
    for (auto &p : midMap) {
        if (p.second.size() <= 1) continue;

        map<float, int> freq;
        for (float s : p.second) freq[s]++;

        int prev = 0;
        for (auto &q : freq) {
            total -= q.second * prev;
            prev  += q.second;
        }
    }

    return total;
}

};