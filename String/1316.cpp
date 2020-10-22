// https://www.acmicpc.net/problem/1316

#include <iostream>
#include <vector>
using namespace std;

bool isGroupWord(string& str){

    vector<bool> check(26, false);

    char groupId = str[0];
    check[groupId-'a'] = true;

    for(int i=0; i<(int)str.length(); i++){
        if(str[i] != groupId){
            groupId = str[i];
            if(check[groupId-'a'] == true){
                return false;
            }else{
                check[groupId-'a'] = true;
            }
        }
    }
    return true;
}

int main(void){
    int query, ans=0;
    cin >> query;
    while(query--){
        string str;
        cin >> str;
        ans += (int)isGroupWord(str);
    }
    cout << ans << '\n';
    return 0;
}
