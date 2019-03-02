#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = (int) 1e5+1000;
typedef long long ll;

int fa[maxn];
int rrank[maxn];
ll num[maxn];
int pa[maxn];

void init(int n){
    for(int i=1;i<=n;i++){
        fa[i] = i;
        rrank[i] = 0;
    }
}

int findd(int x){
    return x == fa[x] ? x : fa[x] = findd(fa[x]);
}

void unit(int x, int y){
    int xx = findd(x);
    int yy = findd(y);
    if( xx == yy){
        return ;
    }
    if(rrank[xx] < rrank[yy]){
        fa[xx] = yy;
        num[yy]+=num[xx];
        num[xx]=0;
    }else{
        fa[yy] = xx;
        if(rrank[x] == rrank[y]){
            rrank[x]++;
            num[xx]+=num[yy];
            num[yy]=0;
        }
    }
}

bool same(int x, int y){
    return findd(x) == findd(y);
}

int main(void){
    int m,n;
    cin >> m >> n;
    init(m);
    for(int i=1;i<=m;i++){
        cin >> num[i];
    }
    int v;
    for(int i=1;i<=m;i++){
        cin >> v;
        unit(i,v);
    }
    for(int i=1;i<=m;i++){
        pa[i] = findd(i);
    }
    for(int i=1;i<=m;i++){
        if(pa[i] == i){
            continue;
        }else{
            num[pa[i]] += num[i];
            num[i] = 0;
        }
    }
//    for(int i=1;i<=m;i++){
//        if(same(i,fa[i])){
//            unit(i,fa[i]);
//        }
//    }
    sort(num+1,num+m+1);
    ll res=0;
    for(int i=m;i>=m-n+1;i--){
        res+=(ll)num[i];
    }
    cout << res << endl;
}