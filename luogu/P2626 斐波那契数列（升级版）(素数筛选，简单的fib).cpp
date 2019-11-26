#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = (int) 1e6 + 100;
bool notprime[maxn];
int prime[maxn], k = 0;

void init() {
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < maxn; i++) {
        if (!notprime[i]) {
            prime[k++] = i;
            if (i > maxn / i)
                continue;
            for (int j = i * i; j < maxn; j += i)
                notprime[j] = true;
        }
    }
}

int solve(int n) {
    ull a = 1, b = 1;
    ull t;
    ull m = pow(2, 31);
//    cout << 1 << ' ' << a << endl;
//    cout << 1 << ' ' << b << endl;
    for(int i = 3; i <= n; i++){
        t = a + b;
        t %= m;
        //cout << i << ' ' << t << endl;
        b = a;
        a = t;
    }
    return a;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << "1=1" << endl;
    }else{
        int m = solve(n);
        int e = m;
        init();
        int ans[1000];
        n = 0;
        for(int i = 0; i < k; i++){
            if(prime[i] * prime[i] > m){
                break;
            }
            if(m % prime[i] == 0){
                while(m % prime[i] == 0){
                    ans[n++] = prime[i];
                    m /= prime[i];
                }
            }
        }
        if(m != 1){
            ans[n++] = m;
        }
        cout << e << '=' << ans[0];
        for(int i = 1; i < n; i++){
            cout << '*' << ans[i];
        }
        cout << endl;
    }

}