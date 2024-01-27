#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    vector<ll> prices(n);
    vector<ll> pages(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    for(int i = 0; i < n; i++)
        cin >> pages[i];

    vector<ll> dp(x + 1);

    for(int i = 0; i < n; i++) {
        ll price = prices[i];
        for(int j = x; j >= 1; j--) {
            if(j - price >= 0)
                dp[j] = max(dp[j], dp[j - price] + pages[i]);
        }
    }


    cout << dp[x];
}