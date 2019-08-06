#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int INF=1e7;
const int maxn=1e4;

typedef long long ll;
typedef pair<int, int> P;

struct point{
    int x, y;
    int sum=0;
};

char maze[maxn][maxn];
int d[maxn][maxn];
int sx, sy, ex, ey;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int m,n,k;

void bfs() {
    int e=0;
    queue<P> que;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && d[nx][ny] == INF && maze[nx][ny] != '#') {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
               /* if(maze[nx][ny] == '@'){
                    e++;
                    if(e==k){
                        return;
                    }
                }*/
            }
        }
    }
}

int main(void){
    while(cin >> m >> n){
        for(int i=0;i<m;i++){
            cin >> maze[i];
        }
        k=0;
        point po[40005];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j] == '@'){
                    po[k].x=i;
                    po[k++].y=j;
                }else if(maze[i][j] == 'Y'){
                    sx=i,sy=j;
                }else if(maze[i][j] == 'M'){
                    ex=i,ey=j;
                }
            }
        }

        bfs();
        for(int i=0;i<k;i++){
            po[i].sum=d[po[i].x][po[i].y];
        }

        sx=ex,sy=ey;
        bfs();
        for(int i=0;i<k;i++){
            po[i].sum+=d[po[i].x][po[i].y];
        }
        int minn=po[0].sum;
        for(int i=1;i<k;i++){
            if(po[i].sum < minn){
                minn = po[i].sum;
            }
        }

        cout << minn*11 << endl;
    }
}