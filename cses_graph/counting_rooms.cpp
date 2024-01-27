#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) 
        cin >> grid[i];


    int ans = 0;

    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '#';
                while(!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();
                    for(auto d: dir) {
                        int ny = y + d.first;
                        int nx = x + d.second;

                        if(ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] == '.') {
                            grid[ny][nx] = '#';
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}