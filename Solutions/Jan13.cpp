#include<iostream>
using namespace std;
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double min_y = INT_MAX ;
        double max_y = INT_MIN ;
        int size = squares.size();
        if(size == 1){
            return (double)squares[0][1] + (double)squares[0][2]/2;
        }
       
        for(int i = 0 ; i < size ; i++){
            min_y = min((double)squares[i][1],min_y);
            max_y = max((double)(squares[i][1]+squares[i][2]),max_y);
        }
        double mid_y = (min_y + max_y)/2;
        for(int iter = 0 ; iter <= 100 ; iter++){
            mid_y = (min_y + max_y)/2;
            double lower_area = 0.0;
            double upper_area = 0.0 ;
            for(int i = 0 ; i < size ; i++){
                double y = squares[i][1];
                double l = squares[i][2];
                if(y >= mid_y){
                    upper_area += l*l;
                }else if(y < mid_y && y+l > mid_y){
                    double ar = mid_y - y;
                    lower_area += ar*l;
                    ar = (y+l -  mid_y);
                    upper_area += ar*l;
                }
                else{
                    lower_area += l*l;
                }
            }
            if(lower_area >= upper_area)
            {
                max_y = mid_y;
            }
            else
            {
                min_y = mid_y;
            }
        }
        return mid_y;
    }
};