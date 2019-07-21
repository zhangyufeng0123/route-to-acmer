#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = (int)1e9 + 7;
const int maxn = (int)1e3+100;
ll num[maxn];
ll fm[maxn];

ll quickmod(ll a, ll b){
    if(b < 0){
        return 0;
    }
    ll ret = 1;
    a %= mod;
    while(b){
        if(b & 1){
            ret = (ret * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

ll inv(ll a){
    return quickmod(a, mod - 2);
}

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
    int n;
    while(cin >> n){

        for(int i = 0; i < n; i++){
            cin >> num[i];
            fm[i] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                fm[i] = fm[i] * (num[j] * num[j] % mod- num[i] * num[i] % mod + mod) % mod;
            }
            fm[i] = inv(fm[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll ret = (inv(num[i]) % mod * inv(2) % mod) * fm[i] % mod;
            ans += ret;
            ans %= mod;
        }
        cout << ans << endl;
    }
}