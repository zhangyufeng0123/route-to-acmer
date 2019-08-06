#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

const int INF=1e9;
const int maxn=205;

typedef pair<int, int> P;

char maze[maxn][maxn];
int d[maxn][maxn];
int sx, sy, ex, ey;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int m,n;
int bfs(){
    queue<P> que;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d[i][j]=INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy]=0;
    while(que.size()){
        P p=que.front();
        que.pop();
        if(p.first == ex && p.second == ey){
            break;
        }
        for(int i=0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] != '#'){
                int tmp=d[p.first][p.second]+1;
                if(maze[nx][ny] == 'x'){
                    tmp++;
                }
                if(tmp < d[nx][ny]){
                    d[nx][ny]=tmp;
                    que.push(P(nx ,ny));
                }
            }
        }
    }
    return d[ex][ey];
}

int main(void){
    while(cin >> m >> n){
        for(int i=0;i<m;i++){
            cin >> maze[i];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j] == 'a'){
                    ex=i,ey=j;
                }else if(maze[i][j] == 'r'){
                    sx=i,sy=j;
                }
            }
        }
        int res=bfs();
        if(res != INF){
            cout << res << endl;
        }else{
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
    }
}