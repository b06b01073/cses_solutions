#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }


    vector<int> roots;

    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            roots.push_back(i);
            vis[i] = true;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();

                for(auto& u: adj[cur]) {
                    if(!vis[u]) {
                        vis[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }

    long long comps = roots.size();

    cout << comps - 1 << endl;
    if(comps >= 2) {
        for(int i = 1; i < comps; i++) {
            cout << roots[0] + 1 << ' ' << roots[i] + 1 << endl; 
        }
    }

}