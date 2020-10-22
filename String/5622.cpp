// https://www.acmicpc.net/problem/5622
#include <iostream>
#include <map>
using namespace std;

void initMap(map<char, int>& m){
    m.insert(make_pair('A', 3)); m.insert(make_pair('B', 3)); m.insert(make_pair('C', 3));
    m.insert(make_pair('D', 4)); m.insert(make_pair('E', 4)); m.insert(make_pair('F', 4));
    m.insert(make_pair('G', 5)); m.insert(make_pair('H', 5)); m.insert(make_pair('I', 5));
    m.insert(make_pair('J', 6)); m.insert(make_pair('K', 6)); m.insert(make_pair('L', 6));
    m.insert(make_pair('M', 7)); m.insert(make_pair('N', 7)); m.insert(make_pair('O', 7));
    m.insert(make_pair('P', 8)); m.insert(make_pair('Q', 8)); m.insert(make_pair('R', 8)); m.insert(make_pair('S', 8));
    m.insert(make_pair('T', 9)); m.insert(make_pair('U', 9)); m.insert(make_pair('V', 9));
    m.insert(make_pair('W', 10)); m.insert(make_pair('X', 10)); m.insert(make_pair('Y', 10)); m.insert(make_pair('Z', 10));
}

int main(void){
    string str;
    cin >> str;
    map<char, int> dial;
    initMap(dial);
    int ans = 0;
    for(int i=0; i<(int)str.length(); i++){
        ans += dial[str[i]];
    }
    cout << ans << '\n';
}