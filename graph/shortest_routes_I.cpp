#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<bool> processed(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(processed[u])
            continue;
        processed[u] = true;

        for(auto& [v, w]: adj[u]) {
            if(w + d < dist[v]) {
                dist[v] = w + d;
                pq.push({w + d, v});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}