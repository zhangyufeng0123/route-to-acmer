#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int) 5e3 + 100;

struct node {
    int h, cost;
};

node apple[maxn];

bool cmp(node &a, node &b) {
    return a.cost < b.cost;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    int h, H;
    cin >> h >> H;
    for (int i = 0; i < n; i++) {
        cin >> apple[i].h >> apple[i].cost;
    }
    sort(apple, apple + n, cmp);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(apple[i].h > h + H){
            continue;
        }
        s -= apple[i].cost;
        if(s == 0){
            ans++;
            break;
        }else if(s < 0){
            break;
        }
        ans++;
    }
    cout << ans << endl;
}