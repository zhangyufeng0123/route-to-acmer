//by ACM-er vegetable birds
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int mod = 100003;

ll powMod(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

void solve() {
    ll m, n;
    cin >> m >> n;
    m %= mod;
    //n %= mod;
    ll a = powMod(m, n);
    ll b = powMod(m - 1, n - 1) * m % mod;
    cout << (a - b + mod) % mod << endl;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    solve();
}