#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& group, vector<vector<int>>& adj, int from, int node, int color) {
    group[node] = color;
    bool valid = true;
    for(auto& next_node: adj[node]) {
        if(next_node == from)
            continue;

        if(group[next_node] == color)
            return false;
        if(group[next_node] != -1)
            continue;
        
        valid &= dfs(group, adj, node, next_node, (color % 2) + 1);
    }

    return valid;
} 

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

    vector<int> group(n + 1, -1);

    for(int i = 1; i <= n; i++) {
        if(group[i] == -1) {
            bool valid = dfs(group, adj, -1, i, 1);
            if(!valid) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << group[i] << ' ';
    }
}