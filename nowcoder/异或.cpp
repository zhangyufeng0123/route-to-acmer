#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, d;
    while(cin >> a >> b >> c >> d){
        if(c > b || d < a){
            cout << "0/1" << endl;
        }else{
            ll f = (d - c + 1) * (1 + b - a);
            if((a <= c && b >= d) || (a >= c && b <= d)){
                ll e = min(b - a, d - c);
                e++;
                ll g = gcd(e, f);
                cout << e / g << '/' << f / g << endl;
            }else{
                ll e;
                if(a >= c && a <= d){
                    e = d - a;
                }else{
                    e = b - c;
                }
                e++;
                ll g = gcd(e, f);
                cout << e / g << '/' << f / g << endl;
            }
        }
    }
}