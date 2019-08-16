#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<set>

using namespace std;

typedef long long ll;

const int maxn = ((1 << 30) - 1) * 2 + 1;

int A, B, C;

struct Hashmap {
    static const int ha = 999917, maxe = 46340;
    int E, link[ha], son[maxe], next[maxe + 5], w[maxe + 5];
    int top, stick[maxe + 5];

    void clear() {
        E = 0;
        while(top){
            link[stick[top--]] = 0;
        }
    }

    void add(int x, int y){
        son[++E] = y;
        next[E] = link[x];
        w[E] = maxn;
        link[x] = E;
    }

    bool count(int y){
        int x = y % ha;
        for(int j = link[x]; j; j = next[j]){
            if(y == son[j]){
                return true;
            }
        }
        return false;
    }

    int &operator[](int y){
        int x = y % ha;
        for(int j = link[x]; j; j = next[j]){
            if(y == son[j]){
                return w[j];
            }
        }

        add(x, y);
        stick[++top] = x;
        return w[E];
    }
}f;

int exgcd(int a, int b, int &x, int &y){
    if (!b){
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}

int BSGS(int a, int b, int c){
    if(c == 1){
        if(!b){
            return a != 1;
        }else{
            return -1;
        }
    }
    if(b == 1){
        if(a){
            return 0;
        }else{
            return -1;
        }
    }
    if(a % c == 0){
        if(!b){
            return 1;
        }else{
            return -1;
        }
    }

    int m = ceil(sqrt((double)c));
    int d = 1;
    int base = 1;
    f.clear();
    for(int i = 0; i <= m - 1; i++){
        f[base] = min(f[base], i);
        base = ((ll) base * a) % c;
    }
    for(int i = 0; i <= m - 1; i++){
        int x, y, r = exgcd(d,c,x,y);
        x = ((ll)x * b % c + c) % c;
        if(f.count(x)){
            return i * m + f[x];
        }
        d = ((ll)d * base) % c;
    }
    return -1;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> C >> A >> B){
        int ans = BSGS(A,B,C);
        if(ans == -1){
            cout << "no solution" << endl;
        }else{
            cout << ans << endl;
        }
    }
}