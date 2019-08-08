#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, mod;

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
        cin >> k >> mod;
        mod *= 6;
        ll sum = (k + 1) * (k + 2) % mod * (k + 3) % mod;
        sum /= 6;
        cout << sum % mod << endl;
    }
    return 0;
}
