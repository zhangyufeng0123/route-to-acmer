#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e3 + 100;
char str[maxn], num[maxn];

int main(void) {
    cin >> str >> num;
    int len1 = strlen(str), len2 = strlen(num);
    int ans = 0;
    for (int i = 0; i < len1; i++) {
        int m = str[i] - '0';
        for (int j = 0; j < len2; j++) {
            int n = num[j] - '0';
            ans += (m * n);
        }
    }
    cout << ans << endl;
}