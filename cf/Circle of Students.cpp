#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int)300;
int num[maxn], judge[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num[i];
        }
        if(n == 1){
            cout << "YES" << endl;
        }else{
            int flag = num[0] - num[1];
            if(abs(flag) != 1){
                if(num[0] == 1 && num[1] == n){
                    flag = 1;
                }else if (num[0] == n && num[1] == 1){
                    flag = -1;
                }
            }
            int k = 0;
            for(int i = 1; i < n; i++){
                if(num[i] - num[(i + 1) % n] != flag){
                    if(flag < 0 && num[i] == n && num[(i + 1) % n] == 1){
                        continue;
                    }else if(flag > 0 && num[i] == 1 && num[(i + 1) % n] == n){
                        continue;
                    }
                    k = 1;
                    break;
                }
            }
            if(k){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }
}