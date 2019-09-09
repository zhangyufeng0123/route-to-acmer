//\\ \\ \\ \\ \\ \\ \\ \\ || || || || || || // // // // // // // //
// \\ \\ \\ \\ \\ \\ \\        _ooOoo_          // // // // // // //
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

const int maxn = (int) 100;
int notPrime[maxn];
int k = 0, prime[maxn];
int amount[30];

void init(){
    notPrime[0] = notPrime[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!notPrime[i]){
            if(i > maxn / i){
                continue;
            }
            for(int j = i * i; j < maxn; j += i){
                notPrime[j] = 1;
            }
        }
    }
}

void Prime(){
    init();
    for(int i = 0; i < maxn; i++){
        if(!notPrime[i]){
            prime[k++] = i;
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

    init();
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        amount[str[i] - 'a']++;
    }
    int maxx = 0, minn = 100;
    for(int i = 0; i < 26; i++){
        if(amount[i] == 0){
            continue;
        }
        if(amount[i] > maxx){
            maxx = amount[i];
        }else if(amount[i] < minn){
            minn = amount[i];
        }
    }
    int ans = maxx - minn;
    if(notPrime[ans]){
        cout << "No Answer" << endl << 0 << endl;
    }else{
        cout << "Lucky Word" << endl << ans << endl;
    }
}