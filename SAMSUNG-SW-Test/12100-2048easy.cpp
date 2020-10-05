#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


int SIZE, ANS;
vector<vector<int>> startState;

void updateAns(const vector<vector<int>>& state){
    int cand = -1;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(state[i][j] > cand){
                cand = state[i][j];
            }
        }
    }
    ANS = max(ANS, cand);
}

vector<vector<int>> moveBoard(vector<vector<int>>& state, int moveDir){
    vector<vector<int>> ret(SIZE, vector<int>(SIZE, 0));
    if(moveDir == UP){
        printf("move up\n");
        for(int col=0; col<SIZE; col++){
            // compress
            vector<int> compress;
            for(int row=0; row<SIZE; row++){
                if(state[row][col] == 0) continue;
                compress.push_back(state[row][col]);
            }
            #ifdef DEBUG
            cout << "compress\n";
            for(int i=0; i<(int)compress.size(); i++){
                cout << compress[i] << " ";
            }
            cout << '\n';
            #endif
            int idx = 0;
            for(int i=0; i<(int)compress.size(); i++){
                if(i+1 < (int)compress.size()){
                    if(compress[i] == compress[i+1]){
                        ret[idx++][col] = compress[i] + compress[i+1];
                        i++;
                    }else{
                        ret[idx++][col] = compress[i];
                    }
                }else{
                    ret[idx][col] = compress[i];
                }
            }
        }
    }else if(moveDir == DOWN){
        printf("move down\n");
        for(int col=0; col<SIZE; col++){
            // compress
            vector<int> compress;
            for(int row=SIZE-1; row>=0; row--){
                if(state[row][col] == 0) continue;
                compress.push_back(state[row][col]);
            }
            int idx = SIZE - 1;
            for(int i=0; i<(int)compress.size(); i++){
                if(i+1 < (int)compress.size()){
                    if(compress[i] == compress[i+1]){
                        ret[idx--][col] = compress[i] + compress[i+1];
                        i++;
                    }else{
                        ret[idx--][col] = compress[i];
                    }
                }else{
                    ret[idx][col] = compress[i];
                }
            }
        }
    }else if(moveDir == LEFT){
        printf("move left\n");
        for(int row=0; row<SIZE; row++){
            // compress
            vector<int> compress;
            for(int col=0; col<SIZE; col++){
                if(state[row][col] == 0) continue;
                compress.push_back(state[row][col]);
            }
            int idx = 0;
            for(int i=0; i<(int)compress.size(); i++){
                if(i+1 < (int)compress.size()){
                    if(compress[i] == compress[i+1]){
                        ret[row][idx++] = compress[i] + compress[i+1];
                        i++;
                    }else{
                        ret[row][idx++] = compress[i];
                    }
                }else{
                    ret[row][idx] = compress[i];
                }
            }
        }
    }else{
        printf("move right\n");
        for(int row=0; row<SIZE; row++){
            // compress
            vector<int> compress;
            for(int col=SIZE-1; col>=0; col--){
                if(state[row][col] == 0) continue;
                compress.push_back(state[row][col]);
            }
            int idx = SIZE - 1;
            for(int i=0; i<(int)compress.size(); i++){
                if(i+1 < (int)compress.size()){
                    if(compress[i] == compress[i+1]){
                        ret[row][idx--] = compress[i] + compress[i+1];
                        i++;
                    }else{
                        ret[row][idx--] = compress[i];
                        //ret[row][idx--] = compress[i+1];
                        //i++;
                    }
                }else{
                    ret[row][idx] = compress[i];
                }
            }
        }
    }
    return ret;
}

void printState(vector<vector<int>>& state){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << state[i][j] << " ";
        }
        cout << '\n';
    }
}




void backTrack(vector<vector<int>>& state, int cnt){
    if(cnt == 5){
        updateAns(state);
        return;
    }
    for(int moveDir=0; moveDir<4; moveDir++){
        // [moveDir] 0:up 1:down 2:left 3:right
        printf("curr state ... \n");
        printState(state);
        vector<vector<int>> nextState = moveBoard(state, moveDir);
        printf("next state ... \n");
        printState(nextState);
        backTrack(nextState, cnt+1);
    }
}

#define SUBMIT
int main(void){
    cin >> SIZE;
    startState.resize(SIZE);
    for(int i=0; i<SIZE; i++){
        startState[i].resize(SIZE);
    }
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cin >> startState[i][j];
        }
    }
    #ifdef SUBMIT
    backTrack(startState, 0);
    cout << ANS << '\n';
    #endif

    #ifdef DEBUG
    vector<vector<int>> temp = moveBoard(startState, UP);
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }
    #endif
    return 0;
}

/*
4
8 16 0 0
0 0 16 8
0 0 0 0
0 0 0 0
answer : 16
correct answer : 32
*/