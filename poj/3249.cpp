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

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e4 + 100;

struct Hash {
    int i;
    ll xi;
    Hash(int a, ll b) : i(a), xi(b) {}
};

vector<Hash> has[maxn];

ll powMod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll res = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return res;
}

ll BSGS(ll x, ll z, ll p) {
    z %= p;
    ll val = 1;
    for (int i = 0; i <= 100; i++, val = (val * x) % p) {
        if (val == z) {
            return i;
        }
    }
    ll q = 1, cnt = 0;
    while ((val = gcd(x, p)) != 1) {
        if (z % val) {
            return -1;
        }
        p /= val;
        z /= val;
        q = q * x / val % p;
        cnt++;
    }

    ll m = (ll) sqrt((double) p);
    for (int i = 0; i < maxn; i++) {
        has[i].clear();
    }
    val = 1;
    for (int i = 0; i <= m; i++) {
        int vv = val % maxn;
        has[vv].push_back(Hash(i, val));
        val = val * x % p;
    }

    ll xm = powMod(x, m, p), a, b;
    for (int i = 0; i <= m; i++) {
        exgcd(q, p, a, b);
        val = ((z * a) % p + p) % p;
        ll vv = val % maxn;
        for (int j = 0; j < has[vv].size(); j++) {
            if (has[vv][j].xi == val) {
                return i * m + has[vv][j].i + cnt;
            }
        }
        q = q * xm % p;
    }
    return -1;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x, y, z, p;
    while (cin >> x >> p >> z){
        if(x && p && z){
            y = BSGS(x, z, p);
            if(y == -1){
                cout << "No Solution" << endl;
            }else{
                cout << y << endl;
            }
        }else{
            break;
        }
    }
}