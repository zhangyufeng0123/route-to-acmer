#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int) 1e4 + 100;
double p[maxn];

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        //cin >> n;
        double maxx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &p[i]);
        }
        sort(p, p + n);
        if(p[n - 1] >= 0.50){
            //cout << fixed << setprecision(12) << p[n - 1] << endl;
            printf("%.12lf\n", p[n - 1]);
        }else{
            double zero = 1 - p[n - 1], one = p[n - 1];
            for(int i = n - 2; i >= 0; i--){
                double one_tmp = one * (1 - p[i]) + zero * p[i];
                if(one_tmp <= one){
                    break;
                }else{
                    zero = zero * (1 - p[i]);
                    one = one_tmp;
                }
            }
            printf("%.12lf\n", one);
            //cout << fixed << setprecision(12) << one << endl;
        }
    }
}