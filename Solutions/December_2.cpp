// Daily DSA — Count Trapezoids
// Date: 2025-12-03


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll countTrapezoids(vector<vector<int>>& points) {

    unordered_map<int, int> freq_of_y;
    for (auto& p : points) {
        freq_of_y[p[1]]++;
    }

    ll total = 0;
    ll sum = 0;

    vector<ll> vec;
    vec.reserve(freq_of_y.size());

    for (auto& [y, count] : freq_of_y) {
        if (count > 1) {
            ll combos = (1LL * count * (count - 1) / 2) % MOD;
            vec.push_back(combos);
        }
    }

    for (ll x : vec) {
        total = (total + (sum * x) % MOD) % MOD;
        sum = (sum + x) % MOD;
    }

    return total;
}
