#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

inline void solve() {
    ll num[3];
    for(int i = 0; i < 3; i++){
        cin >> num[i];
    }
    sort(num, num + 3);
    ll a = gcd(num[0], num[2]);
    num[0] /= a;
    num[2] /= a;
    cout << num[0] << '/' << num[2] << endl;
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