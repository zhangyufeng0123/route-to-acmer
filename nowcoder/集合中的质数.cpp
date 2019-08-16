#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 50;
ll prime[maxn];
int n, m, ans;

void dfs(ll sum, int k, int local, int judge){
    if(sum > m){
        return;
    }

    if(k != 0 && judge == 1){
        if(k % 2 == 1){
            ans += m / sum;
        }else{
            ans -= m / sum;
        }
    }
    if(local > n){
        return;;
    }
    dfs(sum * prime[local], k + 1, local + 1, 1);
    dfs(sum, k, local + 1, 0);
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> prime[i];
    }
    ans = 0;
    dfs(1, 0, 1, 0);
    cout << ans << endl;
}