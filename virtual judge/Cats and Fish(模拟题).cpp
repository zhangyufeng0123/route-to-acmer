//\\ \\ \\ \\ \\ \\ \\ \\ || || || || || || // // // // // // // //
//\\ \\ \\ \\ \\ \\ \\        _ooOoo_          // // // // // // //
//\\ \\ \\ \\ \\ \\          o8888888o            // // // // // //
//\\ \\ \\ \\ \\             88" . "88               // // // // //
//\\ \\ \\ \\                (| -_- |)                  // // // //
//\\ \\ \\                   O\  =  /O                     // // //
//\\ \\                   ____/`---'\____                     // //
//\\                    .'  \\|     |//  `.                      //
//==                   /  \\|||  :  |||//  \                     ==
//==                  /  _||||| -:- |||||-  \                    ==
//==                  |   | \\\  -  /// |   |                    ==
//==                  | \_|  ''\---/''  |   |                    ==
//==                  \  .-\__  `-`  ___/-. /                    ==
//==                ___`. .'  /--.--\  `. . ___                  ==
//==              ."" '<  `.___\_<|>_/___.'  >'"".               ==
//==            | | :  `- \`.;`\ _ /`;.`/ - ` : | |              \\
////            \  \ `-.   \_ __\ /__ _/   .-` /  /              \\
////      ========`-.____`-.___\_____/___.-`____.-'========      \\
////                           `=---='                           \\
//// //   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \\ \\
//// // //      佛祖保佑      永无BUG      永不修改        \\ \\ \\ \\
//// // // // // // || || || || || || || || || || \\ \\ \\ \\ \\ \\

//by ACM-er vegetable birds
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int)1e3;
int num[maxn], sum[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;
    while(cin >> m >> n >> x){
        memset(sum, 0, sizeof(int) * (n + 2));
        for(int i = 0; i < n; i++){
            cin >> num[i];
        }
        sort(num, num + n);
        int ans = 0, ret = 0;
        int rest = m;
        for(int i = 1; i <= x; i++){
            for(int j = 0; j < n; j++){
                if(sum[j] % num[j] == 0 && rest){
                    rest--;
                    sum[j] = 1;
                }else if(sum[j] % num[j] != 0){
                    sum[j]++;
                }
                if(sum[j] % num[j] == 0 && sum[j]){
                    sum[j] = 0;
                    ans++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(sum[i] % num[i]){
                ret++;
            }
        }
        cout << rest << ' ' << ret << endl;
    }
}