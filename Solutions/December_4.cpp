#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int collisions = 0;

        for (char current_state : directions) {
            if (current_state == 'R') {
                st.push(current_state);
            } 
            else if (current_state == 'S') {
                while (!st.empty() && st.top() == 'R') {
                    collisions++;
                    st.pop();
                }
                st.push('S');
            } 
            else { 
                if (!st.empty() && st.top() == 'S') {
                    collisions++;
                } 
                else if (!st.empty() && st.top() == 'R') {
                    collisions += 2;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        collisions++;
                        st.pop();
                    }
                    st.push('S');
                }
            }
        }
        return collisions;
    }
};

int main() {
    Solution obj;

    string directions;
    cin >> directions;

    cout << obj.countCollisions(directions) << endl;

    return 0;
}
