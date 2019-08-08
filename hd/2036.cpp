#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

struct point{
    double x,y;
};

double polygon_area(point *p, int n){
    if(n<3){
        return 0;
    }
    double sum=0;
    p[n+1]=p[1];
    for(int i=1;i<=n;i++){
        sum+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
    }
    sum=fabs(sum/2.0);
    return sum;
}

int main(void){
    int n;
    point po[105];
    while(cin >> n){
        if(!n){
            break;
        }
        for(int i=1;i<=n;i++){
            cin >> po[i].x >> po[i].y;
        }
        printf("%.1lf\n",polygon_area(po,n));
    }
}