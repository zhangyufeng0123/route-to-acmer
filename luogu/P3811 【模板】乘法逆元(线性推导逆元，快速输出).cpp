#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = (int) 3e6 + 10;
ll f[maxn] = {1}, inv[maxn];

inline ll powMod(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % p;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

inline void CalFact(ll n, ll p) {
    //f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * i) % p;
    inv[n] = powMod(f[n], p - 2, p);
    for (int i = n - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}

void write(ll x) {
    if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 ^ 48);
}

inline void solve() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    //cin >> a >> b;
    CalFact(a, b);
    for (int i = 1; i <= a; i++) {
        write(inv[i] * f[i - 1] % b);
        putchar('\n');
        //cout << inv[i] * f[i - 1] % b << endl;
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

    solve();
}