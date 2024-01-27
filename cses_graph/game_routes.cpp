#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    const int mod = (int)1e9 + 7;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev_adj(n + 1);
    vector<int> indegree(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
        indegree[b]++;
    }

    queue<int> q;
    vector<long long> dp(n + 1);
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    dp[1] = 1;


    vector<int> topo;
    while(!q.empty()) {
        int u = q.front();
        q.pop();


        // update the dp
        for(auto& v: rev_adj[u]) {
            dp[u] += dp[v];
            dp[u] %= mod;
        }      

        // update the topo sort
        for(auto& next_node: adj[u]) {
            indegree[next_node]--;
            if(indegree[next_node] == 0)
                q.push(next_node);
        }
    }

    cout << dp[n];
}      