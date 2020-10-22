// https://www.acmicpc.net/problem/2908

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    if(x > y){
        cout << x << '\n';
    }else{
        cout << y << '\n';
    }
}