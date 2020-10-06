#include <iostream>
#include <vector>
using namespace std;

const int N = 0;
const int S = 1;
const int CW = 1;
const int CCW = -1;
const int RIGHT = 2;
const int LEFT = 6;
int gear[4][8], numCmd;

int getCounterDirection(int dir){
    if(dir == CW) return CCW;
    else return CW;
}

void gearRotation(const int target, const int dir){
    int gearCopy[8];
    for(int i=0; i<8; i++){
        gearCopy[i] = gear[target][i];
    }
    if(dir == CW){
        for(int i=1; i<8; i++){
            gear[target][i] = gearCopy[i-1];
        }
        gear[target][0] = gearCopy[7];
    }else{
        for(int i=6; i>=0; i--){
            gear[target][i] = gearCopy[i+1];
        }
        gear[target][7] = gearCopy[0];
    }
}

void gearSimulation(const int target, const int dir, vector<bool>& done){

    if(done[target]) return;

    int selfRight = gear[target][RIGHT];
    int selfLeft = gear[target][LEFT];

    gearRotation(target, dir);
    done[target] = true;

    if(target == 0){
        int rightLeft = gear[target+1][LEFT];
        if(selfRight != rightLeft){
            gearSimulation(target+1, getCounterDirection(dir), done);
        }
    }else if(target == 3){
        int leftRight = gear[target-1][RIGHT];
        if(selfLeft != leftRight){
            gearSimulation(target-1, getCounterDirection(dir), done);
        }
    }else{
        int rightLeft = gear[target+1][LEFT];
        int leftRight = gear[target-1][RIGHT];
        if(selfRight != rightLeft){
            gearSimulation(target+1, getCounterDirection(dir), done);
        }
        if(selfLeft != leftRight){
            gearSimulation(target-1, getCounterDirection(dir), done);
        }
    }    
}

int getScore(){
    int ret = 0;
    if(gear[0][0] == S) ret += 1;
    if(gear[1][0] == S) ret += 2;
    if(gear[2][0] == S) ret += 4;
    if(gear[3][0] == S) ret += 8;
    return ret;
}

int main(void){
    for(int i=0; i<4; i++){
        string str;
        cin >> str;
        for(int j=0; j<8; j++){
            gear[i][j] = str[j]-'0';
        }
    }
    cin >> numCmd;
    for(int i=0; i<numCmd; i++){
        vector<bool> done(4, false);
        int target, dir;
        cin >> target >> dir;
        gearSimulation(target-1, dir, done);
    }
    int score = getScore();
    cout << score << '\n';
    return 0;
}