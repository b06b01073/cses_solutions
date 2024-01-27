#include<bits/stdc++.h>
using namespace std;


vector<long long> dp;

long long solve(int n) {
    if(n >= 0 && n <= 9) 
        return 1;

    if(n < 0)
        return INT_MAX;

    if(dp[n] != INT_MAX)
        return dp[n];


    int k = n;
    while(k) {
        int digit = k % 10;
        if(digit != 0) {
            dp[n] = min(dp[n], solve(n - digit) + 1);
        }
        k /= 10;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    dp.assign(n + 1, INT_MAX);


    cout << solve(n);
}