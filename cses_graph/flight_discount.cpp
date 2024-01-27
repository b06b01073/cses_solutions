#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<ll, ll>;

vector<ll> shortest_path(vector<vector<p>>& adj, int start) {
    int n = adj.size() - 1;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> processed(n + 1);
    dist[start] = 0;

    priority_queue<p, vector<p>, greater<p>> pq;
    
    
    pq.push({0, start});

    while(!pq.empty()) {
        auto node = pq.top();
        int u = node.second;
        ll d = node.first;
        pq.pop();

        if(processed[u])
            continue;
        processed[u] = true;
        for(auto& next: adj[u]) {
            ll w = next.second;
            ll v = next.first;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }

    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<p>> adj(n + 1);
    vector<vector<p>> rev_adj(n + 1);
    vector<vector<ll>> edges(m);

    for(int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        rev_adj[b].push_back({a, w});
        edges[i] = {a, b, w};
    }

    vector<ll> dist_src = shortest_path(adj, 1);
    vector<ll> dist_dst = shortest_path(rev_adj, n);


    ll ans = LLONG_MAX;
    for(auto& edge: edges) {
        auto a = edge[0], b = edge[1], w = edge[2];
        if(dist_src[a] != LLONG_MAX && dist_dst[b] != LLONG_MAX) {
            ans = min(ans, dist_src[a] + dist_dst[b] + w / 2);
        }
    }

    cout << ans;
}