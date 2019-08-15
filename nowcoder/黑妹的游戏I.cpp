#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll tmp1 = gcd(a, b);
        ll ans = gcd(tmp1, c);
        ll res = max(a, max(b, c));

        cout << res / ans - 3 << endl;
    }
    return 0;
}
