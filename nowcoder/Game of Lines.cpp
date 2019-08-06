#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e5 + 10;

struct Point {
    int x;
    int y;
    int flag;
} point[maxn];

int x[300], y[300];
int e = 0;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool cmp(Point &a, Point &b){
    if(a.x * b.y == a.y * b.x){
        return a.flag > b.flag;
    }else{
        return a.x * b.y > a.y * b.x;
    }
}

bool judge(Point a, Point b){
    if(a.x == b.x && a.y == b.y && a.flag == b.flag){
        return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int flag = 0;
    int zerp = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int xx = x[i] - x[j];
            int yy = y[i] - y[j];
            if(yy == 0){
                zerp = 1;
                continue;
            }
            if(xx == 0){
                flag = 1;
                continue;
            }
            int fla = 0;
            if(xx < 0){
                fla++;
                xx = -xx;
            }
            if(yy < 0){
                fla++;
                yy = -yy;
            }
            if(fla & 1){
                point[e].flag = 1;
            }else{
                point[e].flag = 0;
            }
            int s = gcd(xx, yy);
            xx /= s;
            yy /= s;
            point[e].x = xx;
            point[e].y = yy;
            e++;
        }
    }
    sort(point, point + e, cmp);
    int ans = 1;
    for(int i = 1; i < e; i++){
        if(judge(point[i], point[i - 1])){
            ans++;
        }
    }
    ans += (zerp + flag);
    cout << ans << endl;
}