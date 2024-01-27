#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

vector<int> coins;
vector<ll> dp;


int solve(int x) {
    if(x == 0)
        return 1;
    if(x < 0)
        return 0;

    if(dp[x] != -1)
        return dp[x];

    dp[x] = 0;
    for(auto& c: coins) {
        dp[x] += solve(x - c);
        dp[x] %= mod;
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    dp.resize(x + 1, -1);

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    cout << solve(x);
}