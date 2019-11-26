#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int)1e4 + 100;
bool notprime[maxn];
int prime[maxn], k = 0;

void init(){
    notprime[0] = notprime[1] = true;
    for(int i = 2; i < maxn; i++){
        if(!notprime[i]){
            prime[k++] = i;
            if(i > maxn / i)
                continue;
            for(int j = i * i; j < maxn; j += i){
                notprime[j] = true;
            }
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
    for(int i = 4; i <= n; i += 2){
        for(int j = 0; j < k; j++){
            if(!notprime[i - prime[j]]){
                cout << i << '=' << prime[j] << '+' << i - prime[j] << endl;
                break;
            }
        }
    }
}