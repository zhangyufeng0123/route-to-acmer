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

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = (int) 1e3;
char str1[maxn], str2[maxn];
char inum1[maxn], inum2[maxn];
char xnum1[maxn], xnum2[maxn];
char xnum[maxn], inum[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;
    int fp = -1, sp = -1;
    int len1 = strlen(str1), len2 = strlen(str2);
    int lenin1 = 0, lenxn1 = 0, lenin2 = 0, lenxn2 = 0;
    int flag = 0;
    for (int i = 0; i < len1; i++) {
        if(str1[i] == '.'){
            flag++;
            fp = i;
            continue;
        }
        if(!flag){
            inum1[lenin1++] = str1[i];
        }else{
            xnum1[lenxn1++] = str1[i];
        }
    }
    flag = 0;
    for (int j = 0; j < len2; j++) {
        if (str2[j] == '.') {
            sp = j;
            flag++;
            continue;
        }
        if(!flag){
            inum2[lenin2++] = str2[j];
        }else{
            xnum2[lenxn2++] = str2[j];
        }
    }
    if(lenxn1 > lenxn2){
        for(int i = lenxn2; i < lenxn1; i++){
            xnum[i] = xnum1[i];
        }
    }else if(lenxn1 < lenxn2){
        for(int i = lenxn1; i < lenxn2; i++){
            xnum[i] = xnum2[i];
        }
    }
    len1 = min(lenxn1, lenxn2);
    flag = 0;
    for(int i = len1 - 1; i >= 0; i--){
        int tmp = xnum2[i] - '0' + xnum1[i] - '0' + flag;
        flag = 0;
        if(tmp > 9){
            flag = 1;
            tmp -= 10;
        }
        xnum[i] = tmp + '0';
    }
    for(int i = 0; i < lenin1 / 2; i++){
        swap(inum1[i], inum1[lenin1 - i - 1]);
    }
    for(int i = 0; i < lenin2 / 2; i++){
        swap(inum2[i], inum2[lenin2 - i - 1]);
    }
    len2 = min(lenin1, lenin2);
    for(int i = 0; i < len2; i++){
        int tmp = inum1[i] - '0' + inum2[i] - '0' + flag;
        flag = 0;
        if(tmp > 9){
            tmp -= 10;
            flag = 1;
        }
        inum[i] = tmp + '0';
    }
    len2 = max(lenin1, lenin2);
    if(lenin2 > lenin1){
        for(int i = lenin1; i < lenin2; i++){
            int tmp = inum2[i] - '0' + flag;
            flag = 0;
            if(tmp > 9){
                tmp -= 10;
                flag = 1;
            }
            inum[i] = tmp + '0';
        }
        if(flag){
            inum[len2++] = '1';
        }
    }else{
        for(int i = lenin2; i < lenin1; i++){
            int tmp = inum1[i] - '0' + flag;
            flag = 0;
            if(tmp > 9){
                tmp -= 10;
                flag = 1;
            }
            inum[i] = tmp + '0';
        }
        if(flag){
            inum[len2++] = '1';
        }
    }
    for(int i = len2 - 1; i >= 0; i--){
        cout << inum[i];
    }
    if(lenxn1 || lenxn2){
        int k = -1;
        for(int i = 0; i < max(lenxn1, lenxn2); i++){
            if(xnum[i] != '0'){
                k = i;
            }
        }
        if(k != -1){
            cout << '.';
            for(int i = 0; i <= k; i++){
                cout << xnum[i];
            }
        }
    }
    cout << endl;
}