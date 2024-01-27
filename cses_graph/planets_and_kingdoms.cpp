#include<bits/stdc++.h>
using namespace std;

int t = 0;
vector<int> enter_time;
vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<int> order;
vector<bool> processed;
vector<int> kingdoms;

void dfs1(int u) {
    t++;
    enter_time[u] = t;

    for(auto v: adj[u]) {
        if(enter_time[v] == -1) {
            dfs1(v);
        }
    }

    order.push_back(u);
}

void dfs2(int u, int comp) {
    processed[u] = true;
    kingdoms[u] = comp;
    for(auto& v: rev_adj[u]) {
        if(kingdoms[v] == 0) {
            dfs2(v, comp);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    rev_adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }


    enter_time.assign(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if(enter_time[i] == -1)
            dfs1(i);
    }

    processed.resize(n + 1);
    kingdoms.resize(n + 1);
    int comp = 0;
    for(auto it = order.rbegin(); it != order.rend(); it++) {
        if(!processed[*it]) {
            comp++;
            dfs2(*it, comp);
        }
    }

    cout << comp << endl;
    for(int i = 1; i <= n; i++)
        cout << kingdoms[i] << ' ';
}