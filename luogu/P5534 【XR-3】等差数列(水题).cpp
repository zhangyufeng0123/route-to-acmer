#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void solve() {
    ll a, b, d, n;
    cin >> a >> b >> n;
    d = b - a;
    cout << (a + (n - 1) * d + a) * n / 2 << endl;
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