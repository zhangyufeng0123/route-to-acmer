#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e5 + 100;
int a[maxn], b[maxn], n;
stack<int> aa, bb, c;

int main(void) {
    while(cin >> n){
        while(!aa.empty()){
            aa.pop();
        }
        while(!bb.empty()){
            bb.pop();
        }
        while(!c.empty()){
            c.pop();
        }
        aa = c;
        bb = c;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }

        aa.push(a[1]);
        bb.push(b[1]);
        int ans = 1;
        for(int i = 2; i <= n; i++){
            int num1 = 0, num2 = 0;
            if(aa.empty() || aa.top() < a[i]) aa.push(a[i]);
            if(bb.empty() || bb.top() < b[i]) bb.push(b[i]);
            while(!aa.empty() && a[i] < aa.top()){
                aa.pop();
                num1++;
            }
            while(!bb.empty() && b[i] < bb.top()){
                bb.pop();
                num2++;
            }
            aa.push(a[i]);
            bb.push(b[i]);
            if(num1 == num2){
                ans = i;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }
}