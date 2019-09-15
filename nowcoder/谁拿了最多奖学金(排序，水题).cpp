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

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int maxn = (int) 150;

struct node {
    string name;
    int money = 0;
    int order;
} stu[maxn];

bool cmp(node &a, node &b) {
    if(a.money == b.money){
        return a.order < b.order;
    }
    return a.money > b.money;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int grades;
    int access_grades;
    char banganbu;
    char west;
    int amount;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> grades >> access_grades >> banganbu >> west >> amount;
        if (grades > 80 && amount >= 1) {
            stu[i].money += 8000;
        }
        if (grades > 85 && access_grades > 80) {
            stu[i].money += 4000;
        }
        if (grades > 90) {
            stu[i].money += 2000;
        }
        if (grades > 85 && west == 'Y') {
            stu[i].money += 1000;
        }
        if (access_grades > 80 && banganbu == 'Y') {
            stu[i].money += 850;
        }
        sum += stu[i].money;
        stu[i].order = i;
    }

    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl << stu[0].money << endl << sum << endl;
}