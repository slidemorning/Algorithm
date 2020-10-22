// https://www.acmicpc.net/problem/10809
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str;
    cin >> str;
    for(int i=0; i<26; i++){
        int idx = str.find('a'+i);
        if(idx == string::npos) cout << -1 << " ";
        else cout << idx << " ";
    }
    return 0;
}