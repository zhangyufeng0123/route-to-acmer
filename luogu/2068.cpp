#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e5 + 100;

int tree[maxn];
int num = 2;

void update(int index, int n) {
    for (int i = index; i <= num; i += (i & -i)) {
        tree[i] += n;
    }
}

int query_sum(int n) {
    int ans = 0;
    for (int i = n; i > 0; i -= (i & -i)) {
        ans += tree[i];
    }
    return ans;
}

int main(void){
    int n,m;
    cin >> n;
    num=n;
    cin >> m;
    memset(tree,0, sizeof(tree));
    char str;
    int i,j;
    while(m--){
        cin >> str;
        int flag=str-'x';
        switch (flag){
            case 0:{
                cin >> i >> j;
                update(i,j);
            }break;
            case 1:{
                cin >> i >> j;
                cout << query_sum(j) - query_sum(i-1) << endl;
            }break;
            default:
                break;
        }
    }
}
