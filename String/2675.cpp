// https://www.acmicpc.net/problem/2675

#include <iostream>
using namespace std;

int main(void){
    int query;
    cin >> query;
    while(query--){
        int mul;
        string s;
        cin >> mul >> s;
        for(int i=0; i<(int)s.length(); i++){
            for(int j=0; j<mul; j++){
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}