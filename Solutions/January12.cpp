#include<iostream>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            int x1 = points[i][0];  
            int y1 = points[i][1];

            int x2 = points[i+1][0];
            int y2 = points[i+1][1];

            int diff_x = abs(x2 - x1);   
            int diff_y = abs(y2-y1);    

            int dia = min(diff_x,diff_y);
            int left = abs(diff_x - diff_y);

            time += (dia + left);
        }
        return time;
    }
};