#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = int(2e5 + 5);
int num[maxn];

inline void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int ans = m;
    for (int i = 0; i < n - 1; i++) {
        if (num[i + 1] - num[i] > m) {
            ans += m;
        } else {
            ans += (num[i + 1] - num[i]);
        }
    }
    cout << ans << endl;
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