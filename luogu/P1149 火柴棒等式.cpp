#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int) 1e5 + 100;
int num[1000];


void init(){
    num[0] = 6;
    num[1] = 2;
    num[2] = 5;
    num[3] = 5;
    num[4] = 4;
    num[5] = 5;
    num[6] = 6;
    num[7] = 3;
    num[8] = 7;
    num[9] = 6;
//    for(int i = 1; i <= 9; i++){
//        for(int j = 0; j <= 9; j++){
//            num[i * 10 + j]= num[i] + num[j];
//        }
//    }
//    num[100] = 14;
//    for(int i = 101; i <= 109; i++){
//        num[i] = 2 + 6 + num[i % 10];
//    }
//    for(int i = 10; i <= 99; i++){
//        num[100 + i] = num[1] + num[i];
//    }
//    num[200] = 17;
    for(int i = 10; i <= 1000; i++){
        int m = i;
        while(m > 0){
            num[i] += num[m % 10];
            m /= 10;
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
    int n;
    cin >> n;
    n -= 4;
    int ans = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000 -i; j++){
            if(num[i] + num[j] + num[i + j] == n){
                //cout << i << ' ' << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
}