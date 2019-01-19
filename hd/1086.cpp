#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const double eps=1e-10;

struct point{
    double x,y;
};

double min(double a, double b) {
    return a < b ? a : b;
}

double max(double a, double b) {
    return a < b ? b : a;
};

bool inter(point a, point b, point c, point d){
    if (min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y) || min(c.x, d.x) > max(a.x, b.x) || min(c.y, d.y) > max(a.y, b.y)){
        return 0;
    }
    double h,i,j,k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    return h * i <= eps && j * k <= eps;
}

int main(void){
    int n;
    point po1[105],po2[105];
    while(cin >> n){
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> po1[i].x >> po1[i].y >> po2[i].x >> po2[i].y;
        }
        int sum=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(inter(po1[i],po2[i],po1[j],po2[j]))
                    sum++;
            }
        }
        cout << sum << endl;
    }
}