#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct Edge {
    int a;
    int b;
    ll w;
};
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<Edge> edges(m);
 
    for(int i = 0; i < m; i++) {
        auto e = Edge();
        cin >> e.a >> e.b >> e.w;
        edges[i] = e;
    }
 
 
    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
 
    int x;
    for(int i = 0; i < n; i++) {
        x = -1;
        for(auto& e: edges) {
            int a = e.a, b = e.b;
            ll w = e.w;
 
            if(dist[a] != LLONG_MAX) {
 
                if(dist[a] + w < dist[b]) {
                    dist[b] = min(dist[b], dist[a] + w);
                    parent[b] = a;
                    x = b;
                }
            }
        }
    }
 
    // at the n th round, no weight is updated => no negative cycle
    if(x == -1) {
        cout << "NO";
    }
    else {
        for(int i = 0; i < n; i++) {
            x = parent[x];
        }
 
        int init_p = x;
        vector<int> cycle;
 
        while(true) {
            cycle.push_back(x);
            if(x == init_p && cycle.size() > 1)
                break;
 
            x = parent[x];
        }
 
        reverse(cycle.begin(), cycle.end());
 
        cout << "YES\n";
        for(auto& c: cycle)
            cout << c << ' ';
    }
}