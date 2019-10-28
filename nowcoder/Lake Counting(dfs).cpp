//\\ \\ \\ \\ \\ \\ \\ \\ || || || || || || // // // // // // // //
//\\ \\ \\ \\ \\ \\ \\        _ooOoo_          // // // // // // //
//\\ \\ \\ \\ \\ \\          o8888888o            // // // // // //
//\\ \\ \\ \\ \\             88" . "88               // // // // //
//\\ \\ \\ \\                (| -_- |)                  // // // //
//\\ \\ \\                   O\  =  /O                     // // //
//\\ \\                   ____/`---'\____                     // //
//\\                    .'  \\|     |//  `.                      //
//==                   /  \\|||  :  |||//  \                     ==
//==                  /  _||||| -:- |||||-  \                    ==
//==                  |   | \\\  -  /// |   |                    ==
//==                  | \_|  ''\---/''  |   |                    ==
//==                  \  .-\__  `-`  ___/-. /                    ==
//==                ___`. .'  /--.--\  `. . ___                  ==
//==              ."" '<  `.___\_<|>_/___.'  >'"".               ==
//==            | | :  `- \`.;`\ _ /`;.`/ - ` : | |              \\
////            \  \ `-.   \_ __\ /__ _/   .-` /  /              \\
////      ========`-.____`-.___\_____/___.-`____.-'========      \\
////                           `=---='                           \\
//// //   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \\ \\
//// // //      佛祖保佑      永无BUG      永不修改        \\ \\ \\ \\
//// // // // // // || || || || || || || || || || \\ \\ \\ \\ \\ \\

//by ACM-er vegetable birds

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = (int) 150;
char str[maxn][maxn];
int n, m;
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int vis[maxn][maxn];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int xtmp = x + dx[i];
        int ytmp = y + dy[i];
        if (xtmp >= 1 && xtmp <= n && ytmp >= 1 && ytmp <= m) {
            if (!vis[xtmp][ytmp] && str[xtmp][ytmp] == 'W') {
                dfs(xtmp, ytmp);
            }
        }
    }
}


int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && str[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
//    cout << ans << endl;
}