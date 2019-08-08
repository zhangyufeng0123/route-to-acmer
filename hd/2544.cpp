#include <bits/stdc++.h>

using namespace std;
const int MAX_V=20000+1;
const int INF=1e8;
struct edge
{
    int to,cost;
};
typedef pair<int,int> P;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
bool used[MAX_V];
int dijkstra(int s,int t)
{
    priority_queue<P,vector<P>,greater<P> > que;
    memset(used,false,sizeof(used));
    fill(d+1,d+V+1,INT_MAX);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first||used[v])
            continue;
        used[v]=true;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return d[t];
}
int n,m,S,T;
void ini()
{
    for(int i=0;i<=V;i++)
        G[i].clear();
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        if(n==0 && m==0){
            break;
        }
        V = n;
        ini();
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(edge{b, c});
            G[b].push_back(edge{a, c});
        }
        int ans = dijkstra(1, n);
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}