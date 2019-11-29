#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = (int) 1e5 + 100;
const int N = (int) 1e6 + 100;

int prime[maxn], k = 0;
bool notprime[maxn];
bool judge[N];

inline void init() {
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < maxn; i++) {
        if (!notprime[i]) {
            prime[k++] = i;
            if (i > maxn / i)
                continue;
            for (int j = i * i; j < maxn; j += i) {
                notprime[j] = true;
            }
        }
    }
}

inline void solution(int a, int b) {
    for (int i = 0; i < k; i++) {
        int j = a / prime[i];
        if(j == 0 || j == 1){
            j = 2;
        }
        for (; prime[i] * j <= b; j++) {
            if(prime[i] * j < 0)
                break;
            judge[j * prime[i] - a] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i <= b - a; i++) {
        if (!judge[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}

inline void solve() {
    init();
    int a, b;
    cin >> a >> b;
    solution(a, b);
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