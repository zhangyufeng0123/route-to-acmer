#include<iostream>
#include<queue>
using namespace std;
const int INF = 100000000;
const int maxn = 306;
typedef pair<int, int> P;	//储存坐标下x,y
int maze[maxn][maxn];
int d[maxn][maxn];			//储存每个坐标的最短路径
int sx, sy;					//起始坐标
int ex, ey;					//终点坐标
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int n;
int bfs()
{
    queue<P> que;			//bfs用队列
    for (int i = 0; i < n; i++) {		//初始化所有距离为极大
        for (int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == ex && p.second == ey)
            break;
        for (int i = 0; i < 8; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[ex][ey];
}

int main(void){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cin >> sx >> sy;
        cin >> ex >> ey;
        cout << bfs() << endl;
    }
}