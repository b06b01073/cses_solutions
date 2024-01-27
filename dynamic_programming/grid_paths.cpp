#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> grid;

const int mod = int(1e9) + 7;

int solve(int y, int x, vector<vector<ll>>& dp) {
    if(y < 0 || x < 0)
        return 0;

    if(grid[y][x] == '*')
        return 0;

    if(dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    dp[y][x] += solve(y - 1, x, dp) + solve(y, x - 1, dp);
    dp[y][x] %= mod;

    return dp[y][x];
}

int main() {
    int n;
    cin >> n;

    grid.resize(n);
    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    dp[0][0] = 1;
    cout << solve(n - 1, n - 1, dp);


}