#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    vector<vector<int>> rev_adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);

        indegree[b]++;
    }

    queue<int> q;
    vector<int> topo;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        topo.push_back(u);
    
        for(auto& v: adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }    
    }


    vector<int> dist(n + 1);
    vector<int> path(n + 1, -1);
    vector<int> root(n + 1);
    root[1] = 1;

    for(auto& u: topo) {
        for(auto& v: rev_adj[u]) {
            if(dist[v] + 1 > dist[u] && root[v] == 1) {
                dist[u] = dist[v] + 1;
                path[u] = v; 
                root[u] = 1;
            }
        }
    }

    vector<int> ans;
    int node = n;
    while(node != -1) {
        ans.push_back(node);
        node = path[node];
    }

    if(ans.back() != 1) {
        cout << "IMPOSSIBLE";
    }
    else {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;

        for(auto& u: ans)
            cout << u << ' ';
    }

}