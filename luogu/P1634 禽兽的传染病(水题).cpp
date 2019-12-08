#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

inline void solve() {
    ll n, m;
    cin >> n >> m;
    ll ret = 1;
    for(int i = 0; i < m; i++){
        ll tmp = ret * n;
        ret = ret + tmp;
    }
    cout << ret << endl;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}