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

const ll p = 1e4 + 7;
// 1 <= n, m <= 1000000000, 1 < p < 100000, p is prime

const int maxn = 10006;
ll f[maxn], inv[maxn];

ll powMod(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

void CalFact() {
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = (f[i - 1] * i) % p;
    inv[maxn - 1] = powMod(f[maxn - 1], p - 2, p);
    for (int i = maxn - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
}

ll lucas(ll n, ll m, ll p) {
    ll ret = 1;
    while (n && m) {
        ll a = n % p, b = m % p;
        if (a < b) return 0;
        ret = ret * f[a] % p * inv[b] % p * inv[a - b] % p;
        n /= p, m /= p;
    }
    return ret;
}

void solve() {
    ll a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    ll tmp = lucas(k, max(n, m), p);
    cout << (powMod(a, n, p) * powMod(b, m, p) % p) * tmp % p << endl;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    CalFact();
    solve();
}