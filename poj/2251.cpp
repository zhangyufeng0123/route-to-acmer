#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct point{
    int x, y, z;
    int num;
}link[30000];

int vis[31][31][31];
char str[31][31][31];
int qq,pp,t,l,r,c;
int step[6][3]={{1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}};
int flag;

bool judge(int x, int y, int z){
    if(str[x][y][z] == '#' || x < 0 || x >= l || y < 0 || y >= r || z < 0 || z >= c){
        return  false;
    }else{
        return true;
    }
}

void bfs(){
    while(pp < qq){
        for(int i = 0; i < 6; i++){
            int x = link[pp].x + step[i][0];
            int y = link[pp].y + step[i][1];
            int z = link[pp].z + step[i][2];
            if(judge(x, y, z) && vis[x][y][z] == 0){
                if(str[x][y][z] == '.'){
                    vis[x][y][z] = 1;
                    link[qq].x = x;
                    link[qq].y = y;
                    link[qq].z = z;
                    link[qq].num = link[pp].num + 1;
                    qq++;
                }else if(str[x][y][z] == 'E'){
                    flag = 1;
                    t = link[pp].num + 1;
                    break;
                }
            }
        }
        if(flag){
            break;
        }
        pp++;
    }
}

int main(void){
    while(cin >> l >> r >> c){
        if(l == 0 && r == 0 && c == 0){
            break;
        }
        memset(vis, 0, sizeof(vis));
        pp = qq = t =0;
        link[qq].num = 0;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> str[i][j][k];
                    if(str[i][j][k] == 'S'){
                        vis[i][j][k] = 1;
                        link[qq].x = i;
                        link[qq].y = j;
                        link[qq].z = k;
                        qq++;
                    }
                }
            }
        }
        flag = 0;
        bfs();
        if(flag){
            cout<<"Escaped in "<< t <<" minute(s)."<<endl;
        }else{
            cout << "Trapped!" << endl;
        }
    }
}