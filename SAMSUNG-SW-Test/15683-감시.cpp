#include <iostream>
#include <vector>
using namespace std;

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define EMPTY 0
#define WALL 6
#define WATCHED -1

struct Cam{
    int row;
    int col;
    int kind;
    int dir;
};
vector<struct Cam> cam;
vector<int> watchCase;
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
int map[8][8];
int mapRow;
int mapCol;
int ans=8*8;

void watchCam(const int r, const int c, vector<vector<int>>& m, const int dir){
    if(dir == EAST){
        for(int j=c+1; j<mapCol; j++){
            if(m[r][j] == WALL) break;
            if(m[r][j] != EMPTY) continue;
            m[r][j] = WATCHED;
        }
    }else if(dir == SOUTH){
        for(int i=r+1; i<mapRow; i++){
            if(m[i][c] == WALL) break;
            if(m[i][c] != EMPTY) continue;
            m[i][c] = WATCHED;
        }
    }else if(dir == WEST){
        for(int j=c-1; j>=0; j--){
            if(m[r][j] == WALL) break;
            if(m[r][j] != EMPTY) continue;
            m[r][j] = WATCHED;
        }
    }else{
        for(int i=r-1; i>=0; i--){
            if(m[i][c] == WALL) break;
            if(m[i][c] != EMPTY) continue;
            m[i][c] = WATCHED;
        }
    }
}

void watchMap(const struct Cam c, vector<vector<int>>& m){
    if(c.kind == 1){
        watchCam(c.row, c.col, m, c.dir);
    }else if(c.kind == 2){
        if(c.dir == 0){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, WEST);
        }else if(c.dir == 1){
            watchCam(c.row, c.col, m, SOUTH);
            watchCam(c.row, c.col, m, NORTH);
        }else if(c.dir == 2){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, WEST);
        }else{
            watchCam(c.row, c.col, m, SOUTH);
            watchCam(c.row, c.col, m, NORTH);
        }
    }else if(c.kind == 3){
        if(c.dir == 0){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, NORTH);
        }else if(c.dir == 1){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, SOUTH);
        }else if(c.dir == 2){
            watchCam(c.row, c.col, m, SOUTH);
            watchCam(c.row, c.col, m, WEST);
        }else{
            watchCam(c.row, c.col, m, WEST);
            watchCam(c.row, c.col, m, NORTH);
        }
    }else if(c.kind == 4){
        if(c.dir == 0){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, NORTH);
            watchCam(c.row, c.col, m, WEST);
        }else if(c.dir == 1){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, NORTH);
            watchCam(c.row, c.col, m, SOUTH);
        }else if(c.dir == 2){
            watchCam(c.row, c.col, m, EAST);
            watchCam(c.row, c.col, m, SOUTH);
            watchCam(c.row, c.col, m, WEST);
        }else{
            watchCam(c.row, c.col, m, SOUTH);
            watchCam(c.row, c.col, m, NORTH);
            watchCam(c.row, c.col, m, WEST);
        }
    }else{
        watchCam(c.row, c.col, m, EAST);
        watchCam(c.row, c.col, m, NORTH);
        watchCam(c.row, c.col, m, WEST);
        watchCam(c.row, c.col, m, SOUTH);
    }
}

int getBlindSpot(){
    int ret = 0;
    vector<vector<int>> copyMap(mapRow, vector<int>(mapCol, 0));
    for(int i=0; i<cam.size(); i++){
        watchMap(cam[i], copyMap);
    }
    for(int i=0; i<mapRow; i++){
        for(int j=0; j<mapCol; j++){
            if(map[i][j] == EMPTY){
                ret += 1;
            }
        }
    }
    return ret;
}

void setCamDirection(){
    for(int i=0; i<(int)cam.size(); i++){
        cam[i].dir = watchCase[i];
    }
}

void recur(){
    if(watchCase.size() == cam.size()){
        setCamDirection();
        ans = min(ans, getBlindSpot());
    }
    for(int dir=0; dir<4; dir++){
        watchCase.push_back(dir);
        recur();
        watchCase.pop_back();
    }
}

int main(void){
    cin >> mapRow >> mapCol;
    for(int i=0; i<mapRow; i++){
        for(int j=0; j<mapCol; j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5){
                cam.push_back({i, j, map[i][j], 0});
            }
        }
    }
    recur();
    cout << ans << '\n';
}