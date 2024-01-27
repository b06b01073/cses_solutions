#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> parents;
vector<int> sizes;

int find(int a) {
    while(parents[a] != a) {
        a = parents[a];
    }

    return a;
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if(b == a) {
        return false;
    }

    if(sizes[a] < sizes[b])
        swap(a, b);

    parents[b] = a;
    sizes[a] += sizes[b];

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    parents.resize(n + 1);
    for(int i = 1; i <= n; i++)
        parents[i] = i;

    sizes.assign(n + 1, 1);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        if(a != b)
            pq.push({w, a, b});
    }


    ll ans = 0;
    ll unite_count = 0;
    while(!pq.empty()) {
        auto edge = pq.top();
        pq.pop();

        int w = edge[0], a = edge[1], b = edge[2];

        auto ok = unite(a, b);
        if(ok) {
            ans += w;
            unite_count++;
        }
    }

    if(unite_count == n - 1) {
        cout << ans;
    }
    else {
        cout << "IMPOSSIBLE";
    }

}