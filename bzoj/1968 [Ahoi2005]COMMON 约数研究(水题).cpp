//by ACM-er vegetable birds
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ans += n / i;
    }
    cout << ans << endl;
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