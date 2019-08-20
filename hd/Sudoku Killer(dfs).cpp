#include<bits/stdc++.h>

using namespace std;

const int maxn = 10;
int cols[maxn][maxn], rows[maxn][maxn], small[maxn][maxn];
int que_x[maxn * 10], que_y[maxn * 10];
int ans[maxn][maxn];
int k = 0, flag = 0;

void dfs(int n) {
    if (k == n) {
        flag = 1;
        for (int i = 1; i < 10; i++) {
            cout << ans[i][1];
            for (int j = 2; j < 10; j++) {
                cout << ' ' << ans[i][j];
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!cols[que_y[n]][i] && !rows[que_x[n]][i] && !small[(que_x[n]- 1) / 3 * 3 + (que_y[n] - 1) / 3][i]) {
            ans[que_x[n]][que_y[n]] = i;
            cols[que_y[n]][i] = 1;
            rows[que_x[n]][i] = 1;
            small[(que_x[n]- 1) / 3 * 3 + (que_y[n] - 1) / 3][i] = 1;
            dfs(n + 1);
            if (flag) {
                break;
            }
            cols[que_y[n]][i] = 0;
            rows[que_x[n]][i] = 0;
            small[(que_x[n]- 1) / 3 * 3 + (que_y[n] - 1) / 3][i] = 0;
        }
    }
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char tmp;
    int cas = 1;
    while(cin >> tmp){
        if(cas != 1){
            cout << endl;
        }
        cas++;
        memset(small, 0, sizeof(small));
        memset(cols, 0, sizeof(cols));
        memset(rows, 0, sizeof(rows));
        k = 0;
        flag = 0;
        if(tmp == '?'){
            que_x[k] = 1;
            que_y[k++] = 1;
        }else{
            int e = tmp - '0';
            rows[1][e] = 1;
            cols[1][e] = 1;
            small[0][e] = 1;
            ans[1][1] = e;
        }
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if(i == 1 && j == 1){
                    continue;
                }
                cin >> tmp;
                if (tmp == '?') {
                    que_x[k] = i;
                    que_y[k++] = j;
                } else {
                    int e = tmp - '0';
                    rows[i][e] = 1;
                    cols[j][e] = 1;
                    small[(j - 1) / 3 + (i - 1) / 3 * 3][e] = 1;
                    ans[i][j] = e;
                }
            }
        }
        dfs(0);
    }
}