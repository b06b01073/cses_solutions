#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = (int)1e9 + 7;

vector<int> coins;
vector<ll> dp;

int main() {
    int n, x;
    cin >> n >> x;

    dp.resize(x + 1);

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;

        coins.push_back(c);
    }

    dp[0] = 1;
    for(auto& c: coins) {
        for(int i = 1; i <= x; i++) {
            if(i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[x];
}