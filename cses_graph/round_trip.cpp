#include<bits/stdc++.h>
using namespace std;

vector<int> color;
vector<vector<int>> adj;
int begin_node = -1;
int entry_node = -1;
vector<int> parent;

bool dfs(int n, int p = -1) {
    color[n] = 1;
    for(auto& v: adj[n]) {
        if(v == p)
            continue;
        
        if(color[v] == 0) {
            parent[v] = n;
            if(dfs(v, n)) {
                return true;
            }
        }
        else {
            begin_node = n;
            entry_node = v;
            return true;
        }
    }

    color[n] = 2;

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    color.resize(n + 1);
    adj.resize(n + 1);
    parent.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0 && dfs(i)) {
            break;
        }
    }

    if(begin_node == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ans;
    ans.push_back(entry_node);


    int node = begin_node;
    int prev_node = entry_node;
    while(node != entry_node) {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(entry_node);

    cout << ans.size() << endl;
    for(auto& n: ans)
        cout << n << ' ';
}