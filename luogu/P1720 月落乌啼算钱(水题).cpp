#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void solve() {
    int n;
    cin >> n;
    cout << fixed << setprecision(2) << (pow((1.0 + sqrt(5.0)) / 2.0, n) - pow(((1.0 - sqrt(5.0)) / 2), n)) / (sqrt(5.0)) << endl;
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