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

const int maxn = 50;
int ans = 0;
int num[100];

int modular_exp(int a, int m, int n) {
    if (m == 0) {
        return 1;
    }
    if (m == 1) {
        return (a % n);
    }
    ll w = modular_exp(a, m / 2, n);
    w = w * w % n;
    if (m & 1) {
        w = w * a % n;
    }
    return w;
}

bool Miller_Rabin(int n) {
    if (n == 2) {
        return true;
    }
    for (int i = 0; i < maxn; i++) {
        int a = rand() % (n - 2) + 2;
        if (modular_exp(a, n, n) != a) {
            return false;
        }
    }
    return true;
}

void dfs(int n, int m, int k, int sum) {
    if (k == n + 1) {
        if(m){
            return;
        }
        if (Miller_Rabin(sum)) {
            //cout << m << ' ' << sum << endl;
            ans++;
        }
        return;
    }
    if (m > 0 && k != n) {
        dfs(n, m - 1, k + 1, sum);
    }
    dfs(n, m, k + 1, sum + num[k]);
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand(time(NULL));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    dfs(n, n - m, 0, 0);
    cout << ans << endl;
}