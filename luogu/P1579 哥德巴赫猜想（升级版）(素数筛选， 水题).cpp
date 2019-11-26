#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int)2e4 + 100;
bool notprime[maxn];
int prime[maxn], k = 0;

void init(){
    notprime[0] = notprime[1] = true;
    for(int i = 2; i < maxn; i++){
        if(!notprime[i]){
            prime[k++] = i;
            if(i > maxn / i)
                continue;
            for(int j = i * i; j < maxn; j += i)
                notprime[j] = true;
        }
    }
}
int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int n;
    cin >> n;
    for(int i = 0; i < k; i++){
        int flag = 0;
        for(int j = i; j < k; j++){
            if(prime[i] + prime[j] > n){
                break;
            }
            if(!notprime[n - prime[i] - prime[j]]){
                flag = 1;
                cout << prime[i] << ' ' << prime[j] << ' ' << n - prime[i] - prime[j] << endl;
                break;
            }
        }
        if(flag){
            break;
        }
    }
}