#include<iostream>
using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 1, currH = 1;
        int maxV = 1, currV = 1;

        // horizontal bars
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                currH++;
            } else {
                currH = 1;
            }
            maxH = max(maxH, currH);
        }

        // vertical bars
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                currV++;
            } else {
                currV = 1;
            }
            maxV = max(maxV, currV);
        }

        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};