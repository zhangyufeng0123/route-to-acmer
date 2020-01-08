#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = int(1000);
int prime[maxn], notPrime[maxn];
int k = 0;

inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void init() {
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!notPrime[i]) {
            prime[k++] = i;
            if (i > maxn / i) {
                continue;
            }
            for (int j = i * i; j < maxn; j += i) {
                notPrime[j] = 1;
            }
        }
    }
}

void solution(int p, int q) {
    int ans = 0;
    for (int i = 1; i <= p / 2; i++) {
        ans += (i * q / p);
    }
    for (int i = 1; i <= q / 2; i++) {
        ans += (i * p / q);
    }
    cout << "p = " << p << ' ' << "q = " << q << endl;
    cout << ans << endl;
}

void solve() {
    init();
    ull p, q;
//    for(int i = 1; i < k; i++){
//        for(int j = i + 1; j < k; j++){
//            solution(prime[i], prime[j]);
//        }
//    }
    cin >> p >> q;
    if (p == q) {
        ull n = p / 2;
        cout << (1 + n) * n << endl;
    } else {
        cout << (p / 2) * (q / 2) << endl;
    }
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    solve();
}