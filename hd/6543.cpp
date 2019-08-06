#include<bits/stdc++.h>

using namespace std;

const int maxn = (int) 1e7 + 100;
string str1, str2;

int main(void) {
    while (cin >> str1 >> str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (str1 == str2) {
            cout << "Equal" << endl;
        } else if (str1[0] == str2[0] && str1[len1 - 1] == str2[len2 - 1] && len1 == len2) {
            int num1[26], num2[26];
            memset(num1, 0, sizeof(num1));
            memset(num2, 0, sizeof(num2));
            for(int i = 0; i < len1; i++){
                num1[str1[i] - 'a']++;
            }
            for(int i = 0; i < len2; i++){
                num2[str2[i] - 'a']++;
            }
            int flag = 0;
            for(int i = 0; i < 26; i++){
                if(num1[i] != num2[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}