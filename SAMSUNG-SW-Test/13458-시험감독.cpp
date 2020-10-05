#include <iostream>
using namespace std;

int a[1000000];
int n, b, c;

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> b >> c;
    long long ans = 0;
    for(int i=0; i<n; i++){
        a[i] -= b;
        ans += 1;
        if(a[i] <= 0) continue;
        int div = a[i] / c;
        int rmd = a[i] % c;
        if(rmd != 0){
            ans += div + 1;
        }else{
            ans += div;
        }
    }
    cout << ans << '\n';
}