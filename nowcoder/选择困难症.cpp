#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int num[10][105];
int sum[10];
int k,m;

typedef long long ll;

ll ans=0;
ll mul_num[10];

void dfs(int pos, int r) {
    if (pos > k) {
        return;
    }
    for (int i = 0; i <= sum[pos]; i++) {
        if (r + num[pos][i] > m) {
            ans += mul_num[pos + 1] * (sum[pos] - i + 1);
            return;
        }
        dfs(pos + 1, r + num[pos][i]);
    }
}

int main(void){
    while(cin >> k >> m){
        memset(num,0, sizeof(num));
        for(int i=1;i<=k;i++){
            cin >> sum[i];
            for(int j=1;j<=sum[i];j++){
                cin >> num[i][j];
            }
            sort(num[i]+1,num[i]+1+sum[i]);
        }
        mul_num[k+1]=1;
        for(int i=k;i>=1;i--){
            mul_num[i]=mul_num[i+1]*(sum[i]+1);
        }
        ans=0;
        dfs(1,0);
        cout << ans << endl;
    }
}