#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=(int)1e6+1000;
int vis[maxn];
int d[2]={1,-1};
int ex, ey;
int t;

struct node{
    int x;
    int num;
};

void bfs(){
    queue<node> q;
    node now, next;
    node nod={ex, 0};
    q.push(nod);
    vis[ex]=1;
    while(!q.empty()){
        now=q.front();
        if(now.x == ey){
            t=now.num;
            return;
        }
        for(int i=0;i<3;i++){
            if(i==2){
                next.x=now.x*2;
                next.num = now.num + 1;
                if(vis[next.x] == 0 && next.x>=0 && next.x<=100000){
                    q.push(next);
                    vis[next.x] = 1;
                }
            }else{
                next.x = now.x + d[i];
                next.num = now.num + 1;
                if(vis[next.x] == 0 && next.x>=0 && next.x<=100000){
                    q.push(next);
                    vis[next.x] = 1;
                }
            }
        }
        q.pop();
    }
}

int main(void){
    while(cin >> ex >> ey){
        memset(vis,0, sizeof(vis));
        bfs();
        cout << t << endl;
    }
}