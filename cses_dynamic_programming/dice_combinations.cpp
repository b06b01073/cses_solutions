#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = (int)1e9 + 7;


vector<ll> dp;

int solve(int n) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = 0;
    for(int i = 1; i <= 6; i++) {
        dp[n] += solve(n - i);
        dp[n] %= mod;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    dp.assign(n + 1, -1);
    dp[0] = 1;
    cout << solve(n);
}