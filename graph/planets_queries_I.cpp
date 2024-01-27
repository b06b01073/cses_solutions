#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int succ_path[200001][30]; //succ_path[i][j], move 2^j steps from vertice i

int search(int a, int k) {
    int i = 0;
    while((1 << i) <= k) {
        if((1 << i) & k) {
            a = succ_path[a][i];
        }
        i++;
    }

    return a;
}

int max_d = 29;


// Note: resize vector in main or using slow IO may cause TLE

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, q;
    cin >> n >> q;


    for(int i = 1; i <= n; i++) {
        cin >> succ_path[i][0];
    }

    for(int j = 1; j <= max_d; j++) {
        for(int i = 1; i <= n; i++) {
            succ_path[i][j] = succ_path[succ_path[i][j - 1]][j - 1];
        }
    }

    vector<int> ans;

    while(q--) {
        int a, b;
        cin >> a >> b;
        ans.push_back(search(a, b));
    }

  
    for(auto& n: ans)
        cout << n << '\n';
}