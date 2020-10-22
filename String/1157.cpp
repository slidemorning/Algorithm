#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void toUpperCase(string& str){
    for(int i=0; i<(int)str.length(); i++){
        if('a' <= str[i] && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.first > p2.first;
}

int main(void){
    string str;
    cin >> str;
    toUpperCase(str);
    vector<pair<int, int>> v(26, pair<int, int>(0, 0));
    for(int i=0; i<(int)str.length(); i++){
        v[str[i]-'A'].first += 1;
        v[str[i]-'A'].second = str[i];
    }
    sort(v.begin(), v.end(), cmp);
    if(v[0].first == v[1].first){
        cout << '?' << '\n';
    }else{
        cout << (char)v[0].second << '\n';
    }
}