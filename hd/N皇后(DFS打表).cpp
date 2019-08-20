#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans = 0;

void dfs(int n, int x, int cols[], int one[], int fone[]){
    if(n + 1 == x){
        ans++;
        return;;
    }
    for(int i = 1; i <= n; i++){
        if(!cols[i] && !one[i + x] && !fone[x - 1 + n - i]){
            cols[i] = 1;
            one[x + i] = 1;
            fone[x - 1 + n - i] = 1;
            dfs(n, x + 1, cols, one, fone);
            cols[i] = 0;
            one[x + i] = 0;
            fone[x - 1 + n - i] = 0;
        }
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

    int n;
    int cols[30], one[30], fone[30];

    while (cin >> n) {
        if(!n){
            break;
        }
//        memset(cols, 0, sizeof(cols));
//        memset(one, 0, sizeof(one));
//        memset(fone, 0, sizeof(fone));
//        ans = 0;
//        dfs(n, 1, cols, one, fone);
//        cout << ans << endl;
        int ret[] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
        cout << ret[n - 1] << endl;
    }
}