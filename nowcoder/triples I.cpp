#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000;

int num[maxn];
int visit[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n % 3 == 0) {
            cout << 1 << ' ' << n << endl;
            continue;
        } else {
            int k = 0;
            while (n > 0) {
                num[k++] = n % 2;
                n /= 2;
            }
            memset(visit, -1, sizeof(visit));
            int one = 0, two = 0;
            for (int i = 0; i < k; i++) {
                if (i % 2 == 0 && num[i]) {
                    one++;
                } else if(i % 2 && num[i]){
                    two++;
                }
            }

            int sum = one + two * 2;
            int tmp = sum % 3;
            int ones = 0, twos = 0;
            if (one >= 1 && two >= 1) {
                ones = 1;
                twos = 1;
            } else if (two >= 3) {
                twos = 3;
            } else {
                ones = 3;
            }
            int other = 0, amount = 0;
            if (tmp == 2) {
                other = 1;
                amount = 1;
                if (one == 0) {
                    other = 0;
                    amount = 2;
                }
            } else if (tmp == 1) {
                other = 0;
                amount = 1;
                if (two == 0) {
                    other = 1;
                    amount = 2;
                }
            }
            ll tmpe = 0;
            ll tm = 1;
            for (int i = 0; i < k; i++) {
                if (i % 2 == 0 && num[i]) {
                    if (ones > 0) {
                        tmpe += tm;
                        visit[i] = 0;
                        ones--;
                    }
                } else if (i % 2 == 1 && num[i]) {
                    if (twos > 0) {
                        tmpe += tm;
                        visit[i] = 0;
                        twos--;
                    }
                }
                if(!ones && !twos){
                    break;
                }
                tm *= 2;
            }
            cout << 2 << ' ' << tmpe << ' ';
            tmpe = 0;
            tm = 1;
            for(int i = 0; i < k; i++){
                if(visit[i] == -1 && num[i]){
                    tmpe += tm;
                }else if(num[i] && (i + 1) % 2 == other && amount){
                    tmpe += tm;
                    amount--;
                }
                tm *= 2;
            }
            cout << tmpe << endl;
        }
    }

}