#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> min_price(n + 1, LLONG_MAX);
    vector<ll> num_min(n + 1);
    vector<ll> minf(n + 1);
    vector<ll> maxf(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
    }



    min_price[1] = 0;
    num_min[1] = 1;

    vector<bool> processed(n + 1, false);
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});

    while(!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if(processed[u])
            continue;

        processed[u] = true;

        for(auto& [v, w]: adj[u]) {
            if(min_price[u] + w < min_price[v]) {
                min_price[v] = min_price[u] + w;
                num_min[v] = num_min[u];
                maxf[v] = maxf[u] + 1;
                minf[v] = minf[u] + 1;
            
                q.push({min_price[u] + w, v});
            }
            else if(min_price[u] + w == min_price[v]) {
                num_min[v] = (num_min[v] + num_min[u]) % mod;
                maxf[v] = max(maxf[v], maxf[u] + 1);
                minf[v] = min(minf[v], minf[u] + 1);
            }
        }
    }

    cout << min_price[n] << ' ' << num_min[n] << ' ' << minf[n] << ' ' << maxf[n];
}