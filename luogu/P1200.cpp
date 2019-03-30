#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    string str1,str2;
    cin >> str1;
    cin >> str2;
    ll sum1 = 1, sum2 = 1;
    for(int i = 0; i < str1.size();i++){
        ll tmp;
        tmp = str1[i] - 'A' + 1;
        sum1 *= tmp;
    }
    for(int i = 0; i < str2.size(); i++){
        ll tmp;
        tmp = str2[i] - 'A' + 1;
        sum2 *= tmp;
    }
    if(sum1 % 47 == sum2 % 47){
        cout << "GO" << endl;
    }else{
        cout << "STAY" << endl;
    }
}