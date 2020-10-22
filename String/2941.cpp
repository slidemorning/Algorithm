// https://www.acmicpc.net/problem/2941

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string pattern[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string str;
    cin >> str;

    bool flag = false;

    for(int i=0; i<8; i++){
        while(true){
            int index = str.find(pattern[i]);
            if(index != string::npos){
                str.replace(index, pattern[i].length(), "#");
            }else{
                break;
            }
        }
    }

    cout << str.length() << '\n';
}