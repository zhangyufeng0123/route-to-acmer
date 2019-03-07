#include<iostream>
#include<cstring>

using namespace std;

int main(void) {
    int L, n;
    int num[10005];
    memset(num, 0, sizeof(num));
    cin >> L >> n;
    int sum1 = 0, sum2 = 0;
    int j, l, r;
    while (n--) {
        cin >> j >> l >> r;
        if (j) {
            for (int i = l; i <= r; i++) {
                if (num[i] == 1) {
                    num[i] = 2;
                }
            }
        } else {
            for (int i = l; i <= r; i++) {
                if (num[i] == 2) sum1++;
                num[i] = 1;
            }
        }
    }
    for (int i = 0; i <= L; i++) {
        if (num[i] == 2) {
            sum2++;
        }
    }
    cout << sum2 << endl << sum1 << endl;
}