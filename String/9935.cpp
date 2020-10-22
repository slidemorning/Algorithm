// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getps(string& pattern){
    vector<int> ps((int)pattern.length(), 0);
    int j = 0;
    for(int i=1; i<(int)pattern.length(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = ps[j - 1];
        }
        if(pattern[i] == pattern[j]){
            ps[i] = ++j;
        }
    }
    return ps;
}

int kmp(string& str, string& pattern, vector<int>& ps){
    int j=0; // pattern idx
    for(int i=0; i<(int)str.length(); i++){
        while(j > 0 && str[i] != pattern[j]){
            j = ps[j-1];
        }
        if(str[i] == pattern[j]){
            if(j == pattern.length()-1){
                return i - pattern.length() + 1;
            }else{
                j++;
            }
        }
    }
    return -1;
}

int main(void){
    string str;
    string boom;
    cin >> str >> boom;
    vector<int> ps = getps(boom);
    while(true){
        int index = kmp(str, boom, ps);
        //cout << index << '\n';
        if(index != -1){
            string left = str.substr(0, index);
            string right = str.substr(index + boom.length(), str.length()-(index+boom.length()));
            str = left + right;
        }else{
            break;
        }
    }
    if(str.empty()){
        cout << "FRULA" << '\n';
    }else{
        cout << str << '\n';
    }
    return 0;
}
