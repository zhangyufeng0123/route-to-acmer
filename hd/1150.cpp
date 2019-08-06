#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int maxn=105;

int uN,vN; //u,v的数目，使用前面必须赋值
int g[maxn][maxn];
int lnk[maxn],use[maxn];

int dfs(int u)
{
    for(int v=1;v<=vN;v++)
        if(g[u][v]&&!use[v]) //若 use=1 表示这次的查找 曾试图改变过该i的归属问题，但是没有成功，所以就不用费工夫了
        {
            use[v]=1;
            if(lnk[v]==-1||dfs(lnk[v]))
            {
                lnk[v]=u;
                return true;
            }
        }
    return false;
}

int hungary()
{
    int res=0;
    memset(lnk,-1, sizeof(lnk));
    for(int u=1;u<=uN;u++)
    {
        memset(use,0, sizeof(use));
        if(dfs(u)) res++;
    }
    return res;
}

int main(void){
    int k;
    while(cin >> uN){
        if(uN == 0){
            break;
        }
        cin >> vN >> k;
        memset(g,0, sizeof(g));
        for(int i=0;i<k;i++){
            int tmp,x,y;
            cin >> tmp >> x >> y;
            if(x && y){
                g[x][y]=1;
            }
        }
        cout << hungary() << endl;
    }
}