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

const int maxn = 2e5 + 100;

struct node {
    int value;
    int flag;
    int mi;
} num[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            num[k].value = -tmp;
            num[k].flag = -1;
            num[k++].mi = n - i;
        } else if (tmp > 0) {
            num[k].value = tmp;
            num[k].flag = 1;
            num[k++].mi = n - i;
        }
    }
    if (num[0].flag == -1) {
        cout << '-';
    }
    if (num[0].value != 1) {
        cout << num[0].value;
    }
    if (num[0].mi != 0) {
        cout << 'x';
    }
    if (num[0].mi != 1) {
        cout << "^" << num[0].mi;
    }
    for (int i = 1; i < k; i++) {
        if (num[i].flag == 1) {
            cout << '+';
        } else {
            cout << '-';
        }
        if (num[i].value != 1) {
            cout << num[i].value;
        }
        if(num[i].value == 1 && num[i].mi == 0){
            cout << '1';
        }
        if (num[i].mi != 0) {
            cout << 'x';
        }
        if (num[i].mi != 1 && num[i].mi != 0) {
            cout << '^' << num[i].mi;
        }
    }
    cout << endl;
}