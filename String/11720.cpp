// https://www.acmicpc.net/problem/11720
#include <iostream>
using namespace std;

int main(void){
    int length;
    string num;
    cin >> length >> num;
    int ans = 0;
    for(int i=0; i<length; i++){
        ans += (int)(num[i] - '0');
    }
    cout << ans << '\n';
    return 0;
}