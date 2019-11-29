#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


inline void solve(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n % 6){
            cout << "October wins!" << endl;
        }else{
            cout << "Roy wins!" << endl;
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

    solve();
}