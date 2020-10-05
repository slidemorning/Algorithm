#include <iostream>
using namespace std;

enum{
    EAST = 1,
    WEST,
    NORTH,
    SOUTH,
};
struct Dice{
    int top, bottom, front, back, left, right;
};
struct Dice dice;
const int dr[5] = {0, 0, 0, -1, 1};
const int dc[5] = {0, 1, -1, 0, 0};
int mapRowSize, mapColSize;
int diceRow, diceCol;
int numCmd;
int map[20][20];

void initDice(){
    dice.top = 0;
    dice.bottom = 0;
    dice.front = 0;
    dice.back = 0;
    dice.left = 0;
    dice.right = 0;
}

void moveDice(int dir){
    struct Dice temp = dice;
    if(dir == EAST){
        dice.bottom = temp.right;
        dice.top = temp.left;
        dice.left = temp.bottom;
        dice.right = temp.top;
    }else if(dir == WEST){
        dice.top = temp.right;
        dice.bottom = temp.left;
        dice.right = temp.bottom;
        dice.left = temp.top;
    }else if(dir == NORTH){
        dice.top = temp.front;
        dice.back = temp.top;
        dice.bottom = temp.back;
        dice.front = temp.bottom;
    }else{
        dice.bottom = temp.front;
        dice.front = temp.top;
        dice.top = temp.back;
        dice.back = temp.bottom;
    }
}

int diceSimulation(int cmd){
    
    int nextDiceRow = diceRow + dr[cmd];
    int nextDiceCol = diceCol + dc[cmd];

    if(nextDiceRow < 0 || nextDiceRow >= mapRowSize || nextDiceCol < 0 || nextDiceCol >= mapColSize){
        return -1;
    }
    
    moveDice(cmd);

    diceRow = nextDiceRow;
    diceCol = nextDiceCol;

    if(map[diceRow][diceCol] == 0){
        map[diceRow][diceCol] = dice.bottom;
    }else{
        dice.bottom = map[diceRow][diceCol];
        map[diceRow][diceCol] = 0;
    }

    return dice.top;
}


int main(void){
    cin >> mapRowSize >> mapColSize >> diceRow >> diceCol >> numCmd;
    for(int i=0; i<mapRowSize; i++){
        for(int j=0; j<mapColSize; j++){
            cin >> map[i][j];
        }
    }
    initDice();
    for(int i=0; i<numCmd; i++){
        int cmd;
        cin >> cmd;
        int res = diceSimulation(cmd);
        if(res == -1) continue;
        cout << res << '\n';
    }
    return 0;
}