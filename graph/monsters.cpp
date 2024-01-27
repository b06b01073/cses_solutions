#include<bits/stdc++.h>
using namespace std;

char get_dir(pair<int, int> d) {
    auto [dy, dx] = d;
    if(dy == 0 && dx == 1) {
        return 'R';
    }
    else if(dy == 0 && dx == -1) {
        return 'L';
    }
    else if(dy == 1 && dx == 0) {
        return 'D';
    }
    else 
        return 'U';
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    queue<pair<int, int>> monsters;
    queue<vector<int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<string> path(n, string(m, '.'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                monsters.push({i, j});
                dist[i][j] = 0;
            }
            else if(grid[i][j] == 'A') {
                q.push({i, j, 0});
                path[i][j] = 'A';
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    cout << "YES\n";
                    cout << 0;
                    return 0;
                }
            }
        }
    }


    vector<pair<int, int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(!monsters.empty()) {
        auto [y, x] = monsters.front();
        monsters.pop();

        for(auto&d: dir) {
            int ny = y + d.first;
            int nx = x + d.second;

            if(ny >= 0 && nx >= 0 && nx < m && ny < n && dist[ny][nx] == INT_MAX && grid[ny][nx] != '#') {
                dist[ny][nx] = dist[y][x] + 1;
                monsters.push({ny, nx});
            }
        }
    }

    bool flag = false;
    int final_y, final_x;
    while(!q.empty()) {
        auto u = q.front();
        int y = u[0], x = u[1], steps = u[2];
        q.pop();

        for(auto& d: dir) {
            int ny = y + d.first;
            int nx = x + d.second;

            if(ny >= 0 && nx >= 0 && nx < m && ny < n && dist[ny][nx] > steps + 1 && grid[ny][nx] != '#' && path[ny][nx] == '.') {
                path[ny][nx] = get_dir(d);
                
                if(ny == 0 || nx == 0 || ny == n - 1 || nx == m - 1) {
                    final_y = ny;
                    final_x = nx;
                    flag = true;
                    break;
                }
                else {
                    q.push({ny, nx, steps + 1});
                }
            }   
        }

        // escaped
        if(flag)
            break;
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++)
    //         cout << path[i][j];
    //     cout << endl;
    // }


    if(!flag) {
        cout << "NO";
    }
    else {
        cout << "YES\n";

        int y = final_y, x = final_x;
        string ans;
        
        while(path[y][x] != 'A') {
            char last_move = path[y][x];
            ans.push_back(last_move);

            if(last_move == 'R') {
                x--;
            }
            else if(last_move == 'L') {
                x++;
            }
            else if(last_move == 'U') {
                y++;
            }
            else {
                y--;
            }
        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;

        for(auto& p: ans)
            cout << p;
    }
}