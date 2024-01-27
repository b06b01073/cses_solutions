#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);

        indeg[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        auto k = q.front();
        q.pop();
        ans.push_back(k);

        for(auto& u: adj[k]) {
            indeg[u]--;
            if(indeg[u] == 0) {
                q.push(u);
            }
        }
    }
    if(ans.size() != n) {
        cout << "IMPOSSIBLE";
    }
    else {
        for(auto& a: ans)
            cout << a << ' ';
    }
}