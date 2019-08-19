#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a % b, x, y);
    ll temp = y;
    y = x - a / b * y;
    x = temp;
    return r;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, x, y;
    while(cin >> a >> b){
        x = 0, y = 0;
        ll d = exgcd(a, b, x, y);
        if(d != 1){
            cout << "sorry" << endl;
        }else{
            while(x < 0){
                x += b;
                y -= a;
            }
            while(x - b > 0){
                x -= b;
                y += a;
            }
            cout << x << ' ' << y << endl;
        }
    }
}