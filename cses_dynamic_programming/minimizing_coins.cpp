#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = (int)1e9 + 7;

vector<int> coins;
vector<ll> dp;

int solve(int n) {
    if(n == 0)
        return 0;
    if(n < 0)
        return INT_MAX;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = INT_MAX;

    for(auto& c: coins) {
        dp[n] = min(dp[n], solve(n - c) + 1LL);
    }

    return dp[n];
}

int main() {
    int n, x;
    cin >> n >> x;

    dp.assign(x + 1, -1);

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;

        if(c <= x)
            coins.push_back(c);
    }

    int ans = solve(x);
    if(ans == INT_MAX)
        cout << -1;
    else 
        cout << ans;
}