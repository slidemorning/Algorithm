// https://www.acmicpc.net/problem/1152

#include <iostream>
using namespace std;

int main(void){
    string str;
    getline(cin, str);
    int ans = 0;
    for(int i=0; i<(int)str.length(); i++){
        if(str[i] == ' '){
            if(i == 0) continue;
            if(str[i-1] != ' '){
                ans += 1;
            }
        }
        if(i == (int)str.length()-1){
            if(str[i] != ' '){
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}