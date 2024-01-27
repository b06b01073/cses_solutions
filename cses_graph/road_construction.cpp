#include<bits/stdc++.h>
using namespace std;

vector<int> parents;
vector<int> sizes;

int find(int a) {
    while(a != parents[a])
        a = parents[a];

    return a;
}

bool unite(int a, int b) {
    if(a == b) 
        return false;

    if(sizes[a] < sizes[b]) 
        swap(a, b);

    parents[b] = parents[a];
    sizes[a] += sizes[b];

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    sizes.assign(n + 1, 1);
    parents.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    int comps = n, max_size = 1;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a = find(a), b = find(b);
        bool ok = unite(a, b);

        if(ok) {
            comps--;
            max_size = max({max_size, sizes[a], sizes[b]});
        }
        cout << comps << ' ' << max_size << endl;
    }
}