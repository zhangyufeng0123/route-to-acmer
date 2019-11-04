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
typedef unsigned long long ull;

const int maxn = (int) 2e5 + 10;
int a[maxn], b[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    int T, cas = 1;
    //cin >> T;
    scanf("%d", &T);
    a[0] = 0;
    while (T--) {
        int n;
        scanf("%d", &n);
        //cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            //cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            b[i] = a[i] - a[i - 1];
        }
        b[n + 1] = 0 - a[n];
        int flag = 0;
        int p = 4;
        for (int i = 1; i <= n + 1; i++) {
            while(b[i] > 0){
                while (p <= n + 1 && b[p] >= 0) p++;
                if (p - i < 3 || p > n + 1) {
                    flag = 1;
                    break;
                }
                if(b[p] + b[i] > 0){
                    b[i] += b[p];
                    b[p] = 0;
                }else{
                    b[p] += b[i];
                    b[i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (b[i]) {
                flag = 1;
                break;
            }
        }
        printf("Case #%d: ", cas++);
        //cout << "Case #" << cas++ << ": ";
        if (!flag) {
            printf("Yes\n");
            //cout << "Yes" << endl;
        }else{
            printf("No\n");
            //cout << "No" << endl;
        }
    }
}