#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
}

void solve() {
    ll x, y, a, b;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}