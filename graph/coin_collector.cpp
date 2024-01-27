#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> coins;
vector<vector<int>> adj;
vector<vector<int>> rev_adj;

vector<int> enter_time;
vector<int> ordering;

vector<int> comps_label;
vector<ll> comps_coin;

int t = 0;

void dfs1(int u) {
    t++;
    enter_time[u] = t;

    for(auto& v: adj[u]) {
        if(enter_time[v] == -1) {
            dfs1(v);
        }
    }

    ordering.push_back(u);
}

ll dfs2(int u, int label) {
    comps_label[u] = label;
    ll sum = coins[u];
    for(auto& v: rev_adj[u]) {
        if(comps_label[v] == -1) {
            sum += dfs2(v, label);
        }
    }

    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    coins.resize(n + 1);
    adj.resize(n + 1);
    rev_adj.resize(n + 1);
    enter_time.assign(n + 1, -1);
    comps_label.assign(n + 1, -1);
    comps_coin.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }


    for(int i = 1; i <= n; i++) {
        if(enter_time[i] == -1) {
            dfs1(i);
        }
    }


    int label = 0;
    reverse(ordering.begin(), ordering.end()); // LIFO
    for(auto& u: ordering) {
        if(comps_label[u] == -1) {
            label++;
            ll total_coins = dfs2(u, label);
            comps_coin[label] = total_coins;
        }
    }

    int k = label;
    vector<vector<int>> SCC_adj(k + 1);
    for(int i = 1; i <= n; i++) {
        for(auto& v: adj[i]) {
            int src_label = comps_label[i];
            int dst_label = comps_label[v];

            if(src_label != dst_label) {
                SCC_adj[src_label].push_back(dst_label);
            }
        }
    }


    vector<ll> dp(k + 1);
    ll ans = 0;
    for(int i = 1; i <= k; i++)
        dp[i] = comps_coin[i];

    for(int i = 1; i <= k; i++) {
        for(auto& v: SCC_adj[i]) {
            dp[v] = max(dp[v], comps_coin[v] + dp[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
}