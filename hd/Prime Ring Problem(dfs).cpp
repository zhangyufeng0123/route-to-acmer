#include<bits/stdc++.h>

using namespace std;

int prime[50], num[50], ans[50];
int k = 0, flag;
int m;

int isPrime(int n){
    double n_sqrt;
    if(n % 6 != 1 && n % 6 != 5){
        return 0;
    }
    n_sqrt = floor(sqrt(double(n)));
    for(int i = 5; i <= n_sqrt; i += 6){
        if (n % i == 0 || n % (i + 2) == 0){
            return 0;
        }
    }
    return 1;
}

void init(){
    prime[k++] = 2;
    prime[k++] = 3;
    for(int i = 5; i <= 40; i++){
        if(isPrime(i)){
            prime[k++] = i;
        }
    }
}

void dfs(int e, int s){
    if(s == m){
        int y = 0;
        for(int i = 0; i < k; i++){
            if(ans[s - 1] + 1 < prime[i]){
                break;
            }
            if(ans[s - 1] + 1 == prime[i]){
                y = 1;
                break;
            }
        }
        if(!y){
            return;
        }
        cout << '1';
        for(int i = 1; i < s; i++){
            cout << ' ' << ans[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < k; i++){
        if(prime[i] - e > m){
            break;
        }
        if(prime[i] - e <= 0){
            continue;
        }
        if(!num[prime[i] - e]){
            ans[s] = prime[i] - e;
            num[prime[i] - e] = 1;
            dfs(prime[i] - e, s + 1);
            num[prime[i] - e] = 0;
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

    init();
    int cas = 1;
    while(cin >> m){
        cout << "Case " << cas++ << ':' << endl;
        if(m & 1){
            cout << endl;
            continue;
        }
        memset(num, 0, sizeof(num));
        num[0] = 1;
        num[1] = 1;
        flag = 0;
        ans[0] = 1;

        dfs(1, 1);
        cout << endl;
    }
}