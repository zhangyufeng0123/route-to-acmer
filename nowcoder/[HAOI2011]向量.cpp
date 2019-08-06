#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, mod;
int d;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool ok(int a, int b){
    return a % d == 0 && b % d == 0;
}

int main() {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        d = gcd(a, b);
        d <<= 1;
        x %= d;
        y %= d;
        a %= d;
        b %= d;

        if(ok(x, y) || ok(x + a, y + b) || ok(x + b, y + a) || ok(x + a + b, y + a + b)){
            cout << 'Y' << endl;
        }else{
            cout << 'N' << endl;
        }
    }
    return 0;
}
