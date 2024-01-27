#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for(int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }

    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;

        if(dist[u][v] == LLONG_MAX)
            cout << -1 << '\n';
        else 
            cout << dist[u][v] << endl;
    }
}