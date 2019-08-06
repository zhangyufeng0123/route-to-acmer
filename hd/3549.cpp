#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int maxn = (int)1e3+5;
const int inf = (int)1e9;

struct Edge{
    int v, w, next;
};

int s, t;
int n, m, ecnt;
Edge edge[maxn*2];
int head[maxn], dis[maxn], cur[maxn];

void init(){
    ecnt = 0;
    s = 1;
    t = n;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w){
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}

int bfs(){
    memset(dis, -1, sizeof(dis));
    dis[t] = 0;
    queue<int> que;
    que.push(t);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = head[u]; i + 1; i = edge[i].next){
            if(dis[edge[i].v] == -1 && edge[i^1].w > 0){
                dis[edge[i].v] = dis[u] + 1;
                que.push(edge[i].v);
            }
        }
    }

    return dis[s] != -1;
}

int dfs(int u, int v, int flow){
    if(u == t){
        return flow;
    }
    int delta = flow;
    for(int &i = cur[u]; i + 1; i = edge[i].next){
        if(dis[u] == dis[edge[i].v] + 1 && edge[i].w){
            int d = dfs(edge[i].v, v, min(delta, edge[i].w));
            edge[i].w -= d, edge[i ^ 1].w += d;
            delta -= d;
            if(delta == 0) break;
        }
    }
    return flow-delta;
}

int dinic(){
    int ans=0;
    while(bfs()){
        for(int i = 0; i < n; i++){
            cur[i] = head[i];
        }
        ans += dfs(s, t, inf);
    }
    return ans;
}

int main(void){
    int t;
    cin >> t;
    int k=1;
    while(t--){
        cin >> n >> m;
        init();
        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            add_edge(u, v, w);
            add_edge(v, u, 0);
        }

        cout << "Case " << k++ << ": " << dinic() << endl;
    }
}