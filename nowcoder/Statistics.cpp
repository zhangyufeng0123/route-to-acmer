#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e3 + 100;
int num[maxn];

int main(void) {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        ans += num[i];
    }
    double mean = 1.0 * ans / n;
    cout << fixed << setprecision(6) << mean << endl;
    sort(num, num + n);
    double median;
    if(n & 1){
        median = num[n / 2];
    }else{
        median = 1.0 * (num[n / 2] + num[ n / 2 - 1]) / 2;
    }
    cout << fixed << setprecision(6) << median << endl;
}