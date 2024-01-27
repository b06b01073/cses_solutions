#include<bits/stdc++.h>
using namespace std;

vector<int> color;
vector<int> parent;
vector<vector<int>> adj;
int entry = -1;
int start = -1;

bool dfs(int u) {
    color[u] = 1;
    for(auto& v: adj[u]) {
        if(color[v] == 2)
            continue;

        if(color[v] == 0) {
            parent[v] = u;
            if(dfs(v)) {
                return true;
            }
        }
        else {
            entry = v;
            start = u;
            return true;
        }
    }

    color[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        // ignore self loop
        if(a != b)
            adj[a].push_back(b);
    }

    color.assign(n + 1, 0);
    parent.assign(n + 1, 0);

    bool flag = false;
    for(int i = 1; i <= n; i++) {
        if(!color[i] && dfs(i)) {
            break;
        }
    }

    if(start == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        vector<int> ans;
        ans.push_back(entry);

        int node = start;
        while(node != entry) {
            ans.push_back(node);
            node = parent[node];
        }

        ans.push_back(entry);
        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;

        for(auto& k: ans) 
            cout << k << ' ';
    }
}