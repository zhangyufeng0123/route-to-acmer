#include<iostream>

using namespace std;

typedef long long ll;

struct point{
    ll x,y;
};

const int maxn=2010;

point l[maxn],r[maxn];

int main(void){
    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> l[i].x >> l[i].y >> r[i].x >> r[i].y;
    }
    ll le,ri;
    while(n--){
        cin >> le >> ri;
        int sum=0, last;
        for(int i=0;i<m;i++){
            if(le>=l[i].x && le<=r[i].x&&ri>=l[i].y&&ri <=r[i].y){
                sum++;
                last=i+1;
            }
        }
        if(!sum){
            cout << "NO" << endl;
        }else{
            cout << "YES " << sum << ' ' << last << endl;
        }
    }
}