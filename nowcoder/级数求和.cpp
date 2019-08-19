#include<bits/stdc++.h>

using namespace std;

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double n;
    cin >> n;
    int ans = 0;
    double sum = 1;
    for (int i = 2;; i++) {
        sum += 1.0 / i;
        if(sum > n){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}