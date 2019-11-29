#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map<int, int> ma;
const int maxn = (int)5e4 + 100;
int num[maxn];

inline void solve() {
    int T;
    cin >> T;
    while(T--){
        ma.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num[i];
            if(ma.end() != ma.find(num[i])){
                ma[num[i]]++;
            }else{
                ma.insert(pair<int, int>(num[i], 1));
            }
        }
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(ma[num[i]]){
                ma[num[i]] = 0;
                if(flag){
                    cout << ' ' << num[i];
                }else{
                    cout << num[i];
                    flag = 1;
                }
            }
        }
        cout << endl;
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

    solve();
}