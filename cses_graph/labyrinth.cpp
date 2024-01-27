#include<bits/stdc++.h>
using namespace std;

char find_dir(int dy, int dx) {
    if(dy == 1 && dx == 0) {
        return 'D';
    }
    if(dy == -1 && dx == 0) {
        return 'U';
    }

    if(dy == 0 && dx == 1) {
        return 'R';
    }

    if(dy == 0 && dx == -1) {
        return 'L';
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    
    int a_y, a_x;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                a_y = i;
                a_x = j;
            }
        }
    }

    vector<string> path(n, string(m, '.'));

    queue<pair<int, int>> q;
    q.push({a_y, a_x});
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while(!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for(auto& d: dir) {
            int ny = y + d.first;
            int nx = x + d.second;

            if(ny >= 0 && nx >= 0 && ny < n && nx < m) {
                if(grid[ny][nx] == '.') {
                    grid[ny][nx] = find_dir(d.first, d.second);
                    q.push({ny, nx});
                }   
                else if(grid[ny][nx] == 'B') {
                    grid[ny][nx] = find_dir(d.first, d.second);

                    // construct path
                    string path;
                    int y = ny, x = nx;
                    while(grid[y][x] != 'A') {
                        auto last_move = grid[y][x];
                        if(last_move == 'L') {
                            x++;
                        }
                        else if(last_move == 'R') {
                            x--;
                        }
                        else if(last_move == 'U') {
                            y++;
                        }
                        else if(last_move == 'D') {
                            y--;
                        }

                        path.push_back(last_move);
                    }

                    cout << "YES\n";
                    cout << path.size() << endl;
                    reverse(path.begin(), path.end());
                    cout << path;

                    return 0;
                }
            }
        }
    }

    cout << "NO";
}