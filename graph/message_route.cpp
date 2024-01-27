#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1);
    parent[1] = -1;

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        auto u = q.front();
        q.pop();

        bool flag = false;
        for(auto& v: adj[u]) {
            if(parent[v] == 0) {
                parent[v] = u;
                q.push(v);
            }
            if(v == n) {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }


    if(parent[n] == 0) {
        cout << "IMPOSSIBLE";
    }
    else {
        int node = n;
        vector<int> path;
        path.push_back(n);
        while(parent[node] != -1) {
            path.push_back(parent[node]);
            node = parent[node];
        }

        reverse(path.begin(), path.end());
        cout << path.size() << endl;

        for(auto& p: path)
            cout << p << ' ';
    }
}