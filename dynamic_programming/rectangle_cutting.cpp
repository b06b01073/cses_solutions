#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> dp;

int solve(int a, int b) {
    if(b > a)
        swap(a, b);

    if(a == b)
        return 0;

    if(dp[a][b] != -1)
        return dp[a][b];

    dp[a][b] = INT_MAX;

    for(int i = 1; i < a; i++) {
        dp[a][b] = min(dp[a][b], solve(a - i, b) + solve(i, b) + 1);
    }

    for(int i = 1; i < b; i++) {
        dp[a][b] = min(dp[a][b], solve(a, b - i) + solve(a, i) + 1);
    }

    return dp[a][b];
}

int main() {
    int a, b;
    cin >> a >> b;

    if(b > a)
        swap(a, b);

    dp.assign(a + 1, vector<int>(b + 1, -1));
    cout << solve(a, b);
}