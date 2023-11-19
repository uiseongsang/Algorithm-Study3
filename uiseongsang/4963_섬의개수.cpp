#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0,1,1,-1,-1};
const int dx[] = {0,1,0,-1,-1,1,1,-1};
int n,m, ret;
bool vis[51][51];

void dfs(int y, int x, vector<vector<int>> vec) {
    vis[y][x] = true;

    for(int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n  || nx < 0 || nx >= m || vis[ny][nx]) continue;
        if(vec[ny][nx] == 1) {
            dfs(ny,nx,vec);
        }
    }
}

int main() {
    while(true) {

        cin >> m >> n;

        if( n == 0 && m == 0) break;
        
        ret = 0;
        vector<int> v(m,false);
        vector<vector<int>> vec(n,v);
        fill(&vis[0][0], &vis[0][0] + 51 * 51, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> vec[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vec[i][j] == 1 && !vis[i][j]) {
                    ret++;
                    dfs(i,j,vec);
                }
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
