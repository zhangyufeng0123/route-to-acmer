#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = (int)1e4 + 4100;
bool notprime[maxn];
int prime[maxn], k = 0;

inline void init(){
    notprime[0] = notprime[1] = true;
    for(int i = 0 ; i < maxn; i++){
        if(!notprime[i]){
            prime[k++] = i;
            if(i > maxn / i) continue;
            for(int j = i * i; j < maxn; j += i){
                notprime[j] = true;
            }
        }
    }
}

inline void solve() {
    init();
    ll n, m;
    cin >> n >> m;
    int flag = 0;
    for(int i = 0; i < k; i++){
        if(prime[i] > n){
            break;
        }
        for(int j = i + 1; j < k; j++){
            if(prime[j] > n || prime[j] - prime[i] > m){
                break;
            }
            if(prime[j] - prime[i] == m){
                flag = 1;
                cout << prime[i] << ' ' << prime[j] << endl;
            }
        }
    }
    if(!flag){
        cout << "empty" << endl;
    }
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