#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int maxn=1005;

int uN,vN;
int g[maxn][maxn];
int link[maxn],use[maxn];

int dfs(int u){
    for(int v=1;v<=vN;v++){
        if(g[u][v] && !use[v]){
            use[v]=1;
            if(link[v]==-1 || dfs(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungry(){
    int res=0;
    memset(link,-1, sizeof(link));
    for(int u=1;u<=uN;u++){
        memset(use,0, sizeof(use));
        if(dfs(u)){
            res++;
        }
    }
    return res;
}

int main(void){
    int m;
    while(cin >> m){
        if(m == 0){
            break;
        }
        cin >> uN >> vN;
        memset(g,0, sizeof(g));
        while(m--){
            int x,y;
            cin >> x >> y;
            g[x][y]=1;
        }
        cout << hungry() << endl;
    }
}