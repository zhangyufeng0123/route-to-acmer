#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int m, k = 1, tmp;
	cin >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> tmp;
		if (tmp <= m) {
			k++;
		}
	}
	m = 0;
	while (k > 1) {
		k /= 2;
		m++;
	}
	cout << m << endl;
}