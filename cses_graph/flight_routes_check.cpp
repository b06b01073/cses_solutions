#include<bits/stdc++.h>
using namespace std;

int t = 0;
vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<bool> processed;

void dfs(int u, vector<vector<int>>& adj) {
    processed[u] = true;

    for(auto& v: adj[u]) {
        if(!processed[v]) {
            dfs(v, adj);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    rev_adj.resize(n + 1);
    processed.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    dfs(1, adj);

    for(int i = 1; i <= n; i++) {
        if(!processed[i]) {
            cout << "NO" << endl;
            cout << 1 << ' ' << i << endl;
            return 0;
        }
    }

    fill(processed.begin(), processed.end(), false);
    dfs(1, rev_adj);
    for(int i = 1; i <= n; i++) {
        if(!processed[i]) {
            cout << "NO" << endl;
            cout << i << ' ' << 1 << endl;
            return 0;
        }
    }

    cout << "YES";

}