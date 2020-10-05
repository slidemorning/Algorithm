#include <iostream>
using namespace std;

const int DONE = -1;
const int EMPTY = 0;
const int WALL = 1;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int DR[4] = {-1, 0, 1, 0};
const int DC[4] = {0, 1, 0, -1};


struct Robot{
    int row;
    int col;
    int dir;
    int complete;
};
struct Robot robot;
int mapRow, mapCol;
int map[50][50];

int getNextDirection(int dir){
    if(dir == 0) return 3;
    return dir - 1;
}

int getReverseDirection(int dir){
    if(dir == NORTH) return SOUTH;
    else if(dir == SOUTH) return NORTH;
    else if(dir == EAST) return WEST;
    else return EAST;
}

bool indexCondition(int r, int c){
    if(r < 0 || r >= mapRow || c < 0 || c >= mapCol) return false;
    return true;
}

int robotSimulation(){
    
    if(map[robot.row][robot.col] == EMPTY){
        map[robot.row][robot.col] = DONE;
        robot.complete++;
    }

    int flag = 0;

    for(int i=0; i<4; i++){
        int nd = getNextDirection(robot.dir);
        int nr = robot.row + DR[nd];
        int nc = robot.col + DC[nd];
        if(!indexCondition(nr, nc) || map[nr][nc] != EMPTY){
            robot.dir = nd;
            flag++;
        }
        if(indexCondition(nr, nc) && map[nr][nc] == EMPTY){
            robot.dir = nd;
            robot.row = nr;
            robot.col = nc;
            robotSimulation();
        }
    }

    if(flag == 4){
        int rdir = getReverseDirection(robot.dir);
        int nr = robot.row + DR[rdir];
        int nc = robot.col + DC[rdir];
        if(map[nr][nc] != WALL){
            robot.row = nr;
            robot.col = nc;
            robotSimulation();
        }
    }
    return robot.complete;
}

int main(void){
    cin >> mapRow >> mapCol;
    cin >> robot.row >> robot.col >> robot.dir;
    for(int i=0; i<mapRow; i++){
        for(int j=0; j<mapCol; j++){
            cin >> map[i][j];
        }
    }
    cout << robotSimulation() << '\n';
    return 0;
}