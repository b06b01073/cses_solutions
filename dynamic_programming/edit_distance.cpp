#include<bits/stdc++.h>
using namespace std;


int solve(string& a, string& b, vector<vector<int>>& dp, int pa, int pb) {
    if(pa < 0)
        return pb + 1;
    if(pb < 0)
        return pa + 1;
    
    if(dp[pa][pb] != -1)
        return dp[pa][pb];

    if(a[pa] == b[pb]) {
        return dp[pa][pb] = solve(a, b, dp, pa - 1, pb - 1);
    }
    else {
        return dp[pa][pb] = min({solve(a, b, dp, pa - 1, pb), solve(a, b, dp, pa, pb - 1), solve(a, b, dp, pa - 1, pb - 1)}) + 1; 
    }
}


int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << solve(a, b, dp, n - 1, m - 1);
}

