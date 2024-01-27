#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int u, vector<vector<int>>& adj, set<int>& s, vector<bool>& vis) {
    s.insert(u);
    for(auto& v: adj[u]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs(v, adj, s, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> edges(m);
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev_adj(n + 1);
    for(int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;

        edges[i] = {a, b, -w};
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    // edge case: self loop or two nodes
    if(m == 1) {
        int a = edges[0][0], b = edges[0][1], w = -edges[0][2];

        // self loop
        if(a == b) {
            if(w > 0) {
                cout << -1;
            }
            else {
                cout << 0;
            }
        }
        else {
            cout << w;
        }
        return 0;
    }

    
    set<int> source_reachables;
    vector<bool> source_vis(n + 1);
    source_vis[1] = true;
    dfs(1, adj, source_reachables, source_vis);

    set<int> dst_reachables;
    vector<bool> dst_vis(n + 1);
    dst_vis[n] = true;
    dfs(n, rev_adj, dst_reachables, dst_vis);

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    set<int> loops;

    for(int i = 0; i < m; i++) {
        for(auto& e: edges) {
            int a = e[0], b = e[1], w = e[2];
            if(i != m - 1) {
                if(dist[a] != LLONG_MAX) {
                    dist[b] = min(dist[b], dist[a] + w);
                }
            }
            else {
                if(dist[a] + w < dist[b]) {
                    loops.insert(b);
                    loops.insert(a);
                }
            }
        }
    }
    for(auto& l: loops) {
        if(dst_reachables.find(l) != dst_reachables.end() && source_reachables.find(l) != source_reachables.end()) {
            cout << -1;
            return 0;
        }
    }

    cout << -dist[n];
}