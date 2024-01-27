#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    vector<int> count(n + 1);

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, 1});

    int t = 0;
    while(count[n] < k) {
        auto cur = pq.top();
        auto d = cur[0];
        auto u = cur[1];

        pq.pop();

        if(count[u] == k) {
            continue;
        }

        count[u]++;

        if(u == n) {
            cout << d  << ' ';
            t++;
            if(t == k)
                return 0;
        }


        for(auto& next: adj[u]) {
            auto v = next.first;
            auto w = next.second;
            pq.push({d + w, v});
        }

    }

}