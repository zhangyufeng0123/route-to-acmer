#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

const int inf = (int)1e9;
const int maxn = (int)1e6 + 5;
const ll mod = (ll)998244353;
int m, n;
int num[maxn] = { 0 };
int prim[maxn] = { 0 };
bool vis[maxn >> 1] = { false };

int mm,nn;

void initprime() {
    m = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prim[m++] = i;
        }
        for (int j = 0; j < maxn&&i*prim[j] < maxn; j++) {
            vis[i*prim[j]] = 1;
            if (i % prim[j] == 0) {
                break;
            }
        }
    }
}

int cnt[maxn], ans[maxn];

void cal(int x) {
    int xx=x;
    mm=1,nn=1;
    for (int i = 0; i < m&&prim[i] <= x; i++) {
        int cnt = 0;
        while (x%prim[i] == 0) {
            x /= prim[i];
            cnt++;
            if(cnt==2){
                mm*=prim[i];
                cnt=0;
            }
        }
//        as *= (cnt + 1);
//        if (as > 1000000) {
//            return -1;
//        }
    }
    nn=xx/mm/mm;
}

int main(void) {
    initprime();
    int T;
    scanf("%d", &T);
    while (T--) {
        int a;
        scanf("%d", &a);
//        printf("%d\n", ans[a] == -1 ? -1 : ans[a]);
        if(a<0){
            cout << -1 << endl;
        }else{
            cal(a);
            cout << mm << ' ' << nn << endl;
        }
    }
}
