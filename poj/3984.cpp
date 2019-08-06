#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node {
    int x, y;
};

node point1[20], point[20];
int num[10][10];
int minn;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int vis[10][10];

void change() {
    for (int i = 0; i < minn; i++) {
        point[i].x = point1[i].x;
        point[i].y = point1[i].y;
    }
}

void dfs(int x, int y, int sum) {
    if (x == 5 && y == 5) {
        if (sum < minn) {
            minn = sum;
            change();
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (vis[xx][yy] == 0 && num[xx][yy] == 0) {
            vis[xx][yy] = 1;
            point1[sum].x=x;
            point1[sum].y=y;
            dfs(xx, yy, sum + 1);
            vis[xx][yy] = 0;
        }
    }
}

int main(void) {
    memset(num, 1, sizeof(num));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> num[i][j];
        }
    }
    minn = 50;
    dfs(1, 1, 0);
    for(int i=0;i<minn;i++){
        cout << '(' << point[i].x - 1 << ", " << point[i].y - 1 << ')' << endl;
    }
    cout << '(' << 4 << ", " << 4 << ')' << endl;
}