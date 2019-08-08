#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int) 10;
int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int f, s, t;
    cin >> f >> s >> t;
    int e = f * s * t;
    f = e / f;
    s = e / s;
    t = e / t;
    int flag = 0;
    do{
        if((100 * a[0] + 10 * a[1] + a[2]) * f == (100 * a[3] + 10 * a[4] + a[5]) * s &&  (100 * a[3] + 10 * a[4] + a[5]) * s == (100 * a[6] + 10 * a[7] + a[8]) * t){
            flag = 1;
            cout << a[0] << a[1] << a[2] << ' ' << a[3]<< a[4] << a[5] << ' ' << a[6] << a[7] << a[8] << endl;
        }
    }while(next_permutation(a, a + 9));
    if(!flag){
        cout << "No!!!" << endl;
    }
}