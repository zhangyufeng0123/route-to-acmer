#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int) 1e3 + 100;

map<int, int> mp;

bool cmp(int a, int b) {
    return a > b;
}

struct node {
    int n, k;
    int num[maxn];
    int res = 1;

    void solve() {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            add(num[i]);
        }

        cout << res << endl;
    }

    void add(int e) {
        for (auto i = 1; i * i <= e; i++) {
            if (e % i == 0) {
                mp[i]++;
                if (mp[i] >= k) {
                    res = max(res, i);
                }
                if (i * i != e) {
                    mp[e / i]++;
                    if (mp[e / i] >= k) {
                        res = max(res, e / i);
                    }
                }
            }
        }
    }

} ans;

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ans.solve();
}