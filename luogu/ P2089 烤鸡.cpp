#include<bits/stdc++.h>

using namespace std;

const int maxn = (int)1e5;
int ans[maxn][10];
int e = 0;

void print(int num[]){
    for(int i = 0; i < 10; i++){
        ans[e][i] = num[i];
    }
    e++;
}

void dfs(int x, int n, int num[]){
    if(n == 0){
        print(num);
        return;
    }
    if(x >= 10){
        return;
    }
    if(n > (10 - x) * 2){
        return;
    }
    if(n > 2){
        for(int i = 0; i < 3; i++){
            num[x] += i;
            dfs(x + 1, n - i, num);
            num[x] -= i;
        }
    }else{
        for(int i = 0; i <= n; i++){
            num[x] += i;
            dfs(x + 1, n - i, num);
            num[x] -= i;
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
    cin >> n;
    if(n < 10 || n > 30){
        cout << 0 << endl;
    }else{
        int num[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        n -= 10;
        dfs(0, n, num);
        cout << e << endl;
        for(int i = 0; i < e; i++){
            cout << ans[i][0];
            for(int j = 1; j < 10; j++){
                cout << ' ' << ans[i][j];
            }
            cout << endl;
        }
    }
}