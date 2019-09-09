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
//// // //      佛祖保佑      永无BUG      永不修改        \\ \\ \\
//// // // // // // || || || || || || || || || || \\ \\ \\ \\ \\ \\

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, tot;
const int maxn = (int) 100;
int num[maxn], amount;

bool cmp(int a, int b) {
    return a > b;
}

void print(int pre[], int k) {
    cout << pre[0];
    for (int i = 1; i < k; i++) {
        cout << '+' << pre[i];
    }
    cout << endl;
}

void dfs(int sum, int k, int pre[], int e) {
    if (sum == tot) {
        print(pre, k);
        amount++;
        return;
    }

    if (sum > tot ) {
        return;
    }
    for (int i = e; i < n; i++) {
        pre[k] = num[i];
        dfs(sum + num[i], k + 1, pre, i + 1);
        while(num[i] == num[i + 1]){
            i++;
        }
    }
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> tot >> n) {
        if (n == 0 && tot == 0) {
            break;
        }
        cout << "Sums of " << tot << ':' << endl;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num, num + n, cmp);
        amount = 0;
        int ans[100];
        dfs(0, 0, ans, 0);
        if(amount == 0){
            cout << "NONE" << endl;
        }
    }
}