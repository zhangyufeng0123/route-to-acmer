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

/***
*               ii.                                         ;9ABH,
*              SA391,                                    .r9GG35&G
*              &#ii13Gh;                               i3X31i;:,rB1
*              iMs,:,i5895,                         .5G91:,:;:s1:8A
*               33::::,,;5G5,                     ,58Si,,:::,sHX;iH1
*                Sr.,:;rs13BBX35hh11511h5Shhh5S3GAXS:.,,::,,1AG3i,GG
*                .G51S511sr;;iiiishS8G89Shsrrsh59S;.,,,,,..5A85Si,h8
*               :SB9s:,............................,,,.,,,SASh53h,1G.
*            .r18S;..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,.1H315199,rX,
*          ;S89s,..,,,,,,,,,,,,,,,,,,,,,,,....,,.......,,,;r1ShS8,;Xi
*        i55s:.........,,,,,,,,,,,,,,,,.,,,......,.....,,....r9&5.:X1
*       59;.....,.     .,,,,,,,,,,,...        .............,..:1;.:&s
*      s8,..;53S5S3s.   .,,,,,,,.,..      i15S5h1:.........,,,..,,:99
*      93.:39s:rSGB@A;  ..,,,,.....    .SG3hhh9G&BGi..,,,,,,,,,,,,.,83
*      G5.G8  9#@@@@@X. .,,,,,,.....  iA9,.S&B###@@Mr...,,,,,,,,..,.;Xh
*      Gs.X8 S@@@@@@@B:..,,,,,,,,,,. rA1 ,A@@@@@@@@@H:........,,,,,,.iX:
*     ;9. ,8A#@@@@@@#5,.,,,,,,,,,... 9A. 8@@@@@@@@@@M;    ....,,,,,,,,S8
*     X3    iS8XAHH8s.,,,,,,,,,,...,..58hH@@@@@@@@@Hs       ...,,,,,,,:Gs
*    r8,        ,,,...,,,,,,,,,,.....  ,h8XABMMHX3r.          .,,,,,,,.rX:
*   :9, .    .:,..,:;;;::,.,,,,,..          .,,.               ..,,,,,,.59
*  .Si      ,:.i8HBMMMMMB&5,....                    .            .,,,,,.sMr
*  SS       :: h@@@@@@@@@@#; .                     ...  .         ..,,,,iM5
*  91  .    ;:.,1&@@@@@@MXs.                            .          .,,:,:&S
*  hS ....  .:;,,,i3MMS1;..,..... .  .     ...                     ..,:,.99
*  ,8; ..... .,:,..,8Ms:;,,,...                                     .,::.83
*   s&: ....  .sS553B@@HX3s;,.    .,;13h.                            .:::&1
*    SXr  .  ...;s3G99XA&X88Shss11155hi.                             ,;:h&,
*     iH8:  . ..   ,;iiii;,::,,,,,.                                 .;irHA
*      ,8X5;   .     .......                                       ,;iihS8Gi
*         1831,                                                 .,;irrrrrs&@
*           ;5A8r.                                            .:;iiiiirrss1H
*             :X@H3s.......                                .,:;iii;iiiiirsrh
*              r#h:;,...,,.. .,,:;;;;;:::,...              .:;;;;;;iiiirrss1
*             ,M8 ..,....,.....,,::::::,,...         .     .,;;;iiiiiirss11h
*             8B;.,,,,,,,.,.....          .           ..   .:;;;;iirrsss111h
*            i@5,:::,,,,,,,,.... .                   . .:::;;;;;irrrss111111
*            9Bi,:,,,,......                        ..r91;;;;;iirrsss1ss1111
真——手动狗头*/
//by ACM-er vegetable birds

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = (int) 1e5 + 100;

int num[8][20] = {{2, 3, 5, 7}, {23, 29, 31, 37, 53, 59, 71, 73, 79},
                  {233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797},
                  {2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393},
                  {23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331,
                   73939},
                  {233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399},
                  {2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933},
                  {23399339, 29399999, 37337999, 59393339, 73939133}};
int a[8] = {4, 9, 14, 16, 15, 12, 8, 5};

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
    for(int i = 0; i < a[n - 1]; i++){
        cout << num[n - 1][i] << endl;
    }
}