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

const int mod = 998244353;
const int maxn = (int)1e7 + 100;
ll num[maxn];

void init(){
    num[1] = 1;
    for(int i = 2; i <= 10000000; i++){
        num[i] = num[i - 1] * i % mod;
    }
}

ll powMod(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    init();
    while (T--) {
        ll n;
        cin >> n;
        ll ans1, ans2;
        ans1 = (n + 1) * n / 2;
        ans1 %= mod;
        ans1 = ans1 * ans1 % mod;
        ans2 = num[n];
        ans2 = powMod(ans2, n * 2);
        cout << ans1 << ' ' << ans2 << endl;
    }
}