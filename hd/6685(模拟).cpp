#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 150;
int num[1050];
int judge[10];

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
    while (T--) {
        int flag = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            if (num[i] % 10 != 0) {
                flag = 1;
            }
        }
        if (flag) {
            cout << "-1" << endl;
            continue;
        }
        memset(judge, 0, sizeof(judge));
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, num[i]);
            judge[num[i] / 10 % 10] = 1;
        }
        if (judge[2] && !judge[3] && judge[4] && judge[6] && !judge[8]) {
            if(!judge[1] && !judge[5] && !judge[7] && !judge[9]){
                cout << maxx / 100 + 3 << endl;
                continue;
            }else{
                flag = 0;
                if(maxx % 100 != 10){
                    flag = 1;
                }
                if(!flag){
                    for(int i = 0; i < n; i++){
                        if(num[i] % 100 == 0){
                            if(maxx - num[i] == 10){
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        if (!judge[1]) {
                            cout << maxx / 100 + 3 << endl;
                            continue;
                        } else {
                            if (maxx % 100 == 10 && maxx > 100) {
                                int kk = 0;
                                for (int i = 0; i < n; i++) {
                                    if (num[i] == 10) {
                                        kk = 1;
                                        break;
                                    }
                                }
                                if (!kk) {
                                    cout << maxx / 100 - 1 + 4 << endl;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }

        }
        if (judge[0] && judge[1] && !judge[3] && !judge[5] && !judge[8] && judge[9]) {
            if (maxx % 100 == 10 && maxx > 100) {
                int kk = 0;
                for (int i = 0; i < n; i++) {
                    if (num[i] == 10) {
                        kk = 1;
                        break;
                    }
                    if (num[i] % 100 == 0) {
                        if (maxx - num[i] == 10) {
                            kk = 1;
                            break;
                        }
                    }
                }
                if (!kk) {
                    cout << maxx / 100 + 3 << endl;
                    continue;
                }
            }
        }
        if (!judge[0] && judge[1] && judge[2] && !judge[3] && judge[4] && judge[5] && judge[6] && judge[7] &&
            !judge[8] && judge[9]) {
            if (maxx % 100 == 10 && maxx > 10) {
                int kk = 0;
                for (int i = 0; i < n; i++) {
                    if (num[i] == 10) {
                        kk = 1;
                        break;
                    }
                }
                if (!kk) {
                    cout << maxx / 100 + 3 << endl;
                    continue;
                }
            }
        }
        int res[5] = {0};
        int nu[] = {5, 2, 1};
        int hundred = 0;
        for (int i = 0; i < n; i++) {
            hundred = max(hundred, num[i] / 100);
            int tmp = num[i] % 100;
            tmp /= 10;
            for (int j = 0; j < 3; j++) {
                int tmpe = tmp / nu[j];
                res[j] = max(tmpe, res[j]);
                tmp %= nu[j];
            }
        }
        int ret[5];
        maxx %= 100;
        maxx /= 10;
        for (int i = 0; i < 3; i++) {
            ret[i] = maxx / nu[i];
            maxx %= nu[i];
        }
        if (!judge[6] && !judge[7] && !judge[8] && !judge[9] && judge[5]) {
            if (res[1] == 2 && res[2] == 1) {
                res[0] = 0;
                ret[0] = 0;
            }
        }
        int e = 0;
        for (int i = 0; i < 3; i++) {
            if (res[i] > ret[i]) {
                e += (res[i] - ret[i]);
            }
        }
        if (e > 3) {
            cout << hundred + 3 << endl;
        } else {
            cout << hundred + ret[0] + ret[1] + ret[2] + e << endl;
        }
    }
}