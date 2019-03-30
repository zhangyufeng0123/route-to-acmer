#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    int num[20];
    int k = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int tmp = str[i] - '0';
            num[k++] = tmp;
        }
        if(str[i] == 'X'){
            num[k++] = 10;
        }
    }
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum = sum + num[i] * (i + 1);
    }
    sum = sum % 11;
    if(sum == num[9]){
        cout << "Right" << endl;
    }else{
        char tmpe;
        if(sum == 10){
            tmpe = 'X';
        }else{
            tmpe = '0' + sum;
        }
        str[str.size()-1] = tmpe;
        cout << str << endl;
    }
}