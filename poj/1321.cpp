#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int m,n;
char str[10][10];
int num[10][10];
ll res, row[10];

void dfs(int ceng, int sum){
    if(sum == n){
        res++;
        return;
    }
    if(ceng == m){
        return;
    }
    dfs(ceng + 1, sum);
    for(int i = 0; i < m; i++){
        if(row[i] == 0 && num[ceng][i] == 1){
            row[i] = 1;
            dfs(ceng + 1, sum + 1);
            row[i] = 0;
        }
    }
}

int main(void){
    while(cin >> m >> n){
        if(m == -1 && n == -1){
            break;
        }
        memset(num,0, sizeof(num));
        memset(row,0, sizeof(row));
        for(int i=0;i<m;i++){
            cin >> str[i];
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(str[i][j] == '#'){
                    num[i][j] = 1;
                }
            }
        }

        res=0;
        dfs(0, 0);
        cout << res << endl;
    }
}