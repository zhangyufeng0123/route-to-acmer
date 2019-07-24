#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 3e3 + 100;
const int mod = 998244353;
ll fz[maxn];
int n;

ll quickpow(ll a, ll b) {
    if (b < 0) {
        return 0;
    }
    ll ret = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

ll inv(ll a) {
    return quickpow(a, mod - 2);
}

void init() {
    fz[1] = 0;
    fz[2] = 2;
    for (int i = 3; i <= 3000; i++) {
        fz[i] = i * (i - 1) + fz[i - 1];
        fz[i] %= mod;
    }
}

int main(void) {
    init();
    while(cin >> n){
        ll fm = n * 3;
        cout << inv(fm) * fz[n] % mod << endl;
    }
}