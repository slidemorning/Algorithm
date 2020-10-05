#include <iostream>
using namespace std;

int n, synergy[20][20], ans = 10*100;
bool chk[20];

void update(){
    int tt = 0, ft = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chk[i] == true && chk[j] == true) tt += synergy[i][j];
            if(chk[i] == false && chk[j] == false) ft += synergy[i][j];
        }
    }
    int tmp = tt - ft;
    if(tmp < 0) tmp *= -1;
    ans = min(ans, tmp);
}

void recur(int idx, int cnt){
    if(cnt == n/2){
        update();
        return;
    }
    for(int i=idx; i<n; i++){
        if(chk[i] == true) continue;
        chk[i] = true;
        recur(i+1, cnt+1);
        chk[i] = false;
    }
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> synergy[i][j];
        }
    }
    recur(0, 0);
    cout << ans << '\n';
}