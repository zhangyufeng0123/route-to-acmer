#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(void){
    long long dp[60];
    dp[1]=1;
    dp[2]=2;
    for(int i = 3; i < 55; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        cout << dp[m-n] << endl;
    }
}