#include <iostream>
#include <deque>
using namespace std;

struct Snake{
    deque<pair<int, int>> pos;
    int dir;
};
struct Snake snake;
const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1}; // up right down left
int boardSize, numApple, board[101][101];
char cmd[10001];
void printBoardState();

void initSnake(){
    board[1][1] = SNAKE;
    snake.pos.push_back({1, 1}); 
    snake.dir = 1;
}

/*
    [snake.pos]
    Deque : front <tail . . . head> back
    [snake.dir]
    direction : Up(0), Right(1), Down(2), Left(3)
    [command]
    'L' : Turn left (direction--)
    'D' : Turn Right (direction++)
*/
bool moveSnake(){
    int headRow = snake.pos.back().first;
    int headCol = snake.pos.back().second;
    int nextHeadRow = headRow + dr[snake.dir];
    int nextHeadCol = headCol + dc[snake.dir];
    if(nextHeadRow < 1 || nextHeadCol < 1 || nextHeadRow > boardSize || nextHeadCol > boardSize){
        return false;
    }
    if(board[nextHeadRow][nextHeadCol] == SNAKE){
        return false;
    }
    if(board[nextHeadRow][nextHeadCol] == APPLE){
        board[nextHeadRow][nextHeadCol] = SNAKE;
        snake.pos.push_back({nextHeadRow, nextHeadCol});
    }
    else if(board[nextHeadRow][nextHeadCol] == EMPTY){
        board[nextHeadRow][nextHeadCol] = SNAKE;
        snake.pos.push_back({nextHeadRow, nextHeadCol});
        int tailRow = snake.pos.front().first;
        int tailCol = snake.pos.front().second;
        board[tailRow][tailCol] = EMPTY;
        snake.pos.pop_front();
    }
    return true;
}

void changeSnakeDirection(char dir){
    //cout << "change snake direction to " << dir << '\n';
    if(dir == 'D'){
        snake.dir += 1;
        if(snake.dir >= 4){
            snake.dir = 0;
        }
    }else{
        snake.dir -= 1;
        if(snake.dir < 0){
            snake.dir = 3;
        }
    }
}

int snakeSimulation(){
    int sec = 1;
    while(true){
        //cout << "curr sec : " << sec << '\n';
        //printBoardState();
        if(moveSnake()){
            if(cmd[sec] == 'L' || cmd[sec] == 'D'){
                changeSnakeDirection(cmd[sec]);
            }
            sec += 1;
        }else{
            return sec;
        }
    }
}

// Function for DEBUG
void printBoardState(){
    for(int i=1; i<=boardSize; i++){
        for(int j=1; j<=boardSize; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(void){
    cin >> boardSize >> numApple;
    for(int i=0; i<numApple; i++){
        int row, col;
        cin >> row >> col;
        board[row][col] = APPLE;
    }
    int numChangeDir;
    cin >> numChangeDir;
    for(int i=0; i<numChangeDir; i++){
        int sec;
        char dir;
        cin >> sec >> dir;
        cmd[sec] = dir;
    }
    initSnake();
    cout << snakeSimulation() << '\n';
    return 0;
}