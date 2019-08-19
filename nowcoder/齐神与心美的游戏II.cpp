#include<bits/stdc++.h>

using namespace std;

int n;
const int maxn = (int) 6e5+100;
int judge[maxn], num[200];

int gcd(int a, int b){
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

    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    int ans = 0;
    int amount = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int e = 0; e < n; e++){
                amount++;
                if(num[i] + num[j] + num[e] == k){
                    ans++;
                }
            }
        }
    }
    if(ans == 0){
        cout << "0/1" << endl;
        return 0;
    }
    int d = gcd(ans, amount);
    ans /= d;
    amount /= d;
    cout << ans << '/' << amount << endl;
}