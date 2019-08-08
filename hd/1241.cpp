#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int m, n;
int num[105][105];
char mapp[105][105];
int vis[105][105];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int sum;

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (vis[xx][yy] == 0 && num[xx][yy] == 1) {
            vis[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
}

int main(void) {
    while (cin >> m >> n) {
        sum=0;
        if (m == 0) {
            break;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mapp[i][j];
            }
        }
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mapp[i][j] == '@') {
                    num[i][j] = 1;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (num[i][j] == 1 && vis[i][j] == 0) {
                    sum++;
                    vis[i][j] = 1;
                    dfs(i, j);
                }
            }
        }
        cout << sum << endl;
    }
}