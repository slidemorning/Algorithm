#include <iostream>
#include <queue>
using namespace std;

struct State{
    int rr, rc, br, bc;
};
struct State state;
int rows, cols;
int dist[10][10][10][10];
const int dc[4] = {-1, 1, 0, 0};
const int dr[4] = {0, 0, -1, 1};

char board[10][10];

struct State moveBall(struct State curr, int dir){
    int rr = curr.rr;
    int rc = curr.rc;
    int br = curr.br;
    int bc = curr.bc;
    int nr = rr;
    int nc = rc;
    while(true){
        nr = rr + dr[dir];
        nc = rc + dc[dir];
        if(board[nr][nc] == '#'){
            break;
        }
        rr = nr;
        rc = nc;
        if(board[rr][rc] == 'O'){
            break;
        }
    }
    nr = br;
    nc = bc;
    while(true){
        nr = br + dr[dir];
        nc = bc + dc[dir];
        if(board[nr][nc] == '#'){
            break;
        }
        br = nr;
        bc = nc;
        if(board[br][bc] == 'O'){
            break;
        }
    }
    return {rr, rc, br, bc};
}

int bfs(){
    queue<struct State> q;
    dist[state.rr][state.rc][state.br][state.bc] = 1;
    q.push(state);
    while(!q.empty()){
        struct State curr = q.front();
        q.pop();
        if(board[curr.rr][curr.rc] == 'O' && board[curr.br][curr.bc] != 'O'){
            return dist[curr.rr][curr.rc][curr.br][curr.bc] - 1;
        }
        for(int dir=0; dir<4; dir++){
            struct State next = moveBall(curr, dir);
            if(board[next.br][next.bc] == 'O') continue;
            if(next.rr == next.br && next.rc == next.bc){
                if(dir == 0){
                    // left
                    curr.rc < curr.bc ? next.bc++ : next.rc++;
                }else if(dir == 1){
                    // right
                    curr.rc < curr.bc ? next.rc-- : next.bc--;
                }else if(dir == 2){
                    // up
                    curr.rr < curr.br ? next.br++ : next.rr++;
                }else{
                    // down
                    curr.rr < curr.br ? next.rr-- : next.br--;
                }
            }
            if(dist[next.rr][next.rc][next.br][next.bc] == 0){
                dist[next.rr][next.rc][next.br][next.bc] = dist[curr.rr][curr.rc][curr.br][curr.bc] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void){
    cin >> rows >> cols;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> board[i][j];
            if(board[i][j] == 'B'){
                state.br = i;
                state.bc = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'R'){
                state.rr = i;
                state.rc = j;
                board[i][j] = '.';
            }
        }
    }
    int ans = bfs();
    if(ans > 10){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
    return 0;
}