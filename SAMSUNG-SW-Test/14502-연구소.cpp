#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define EMPTY 0
#define WALL 1
#define VIRUS 2
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
int lab[8][8], labRow, labCol, ans=0;
vector<pair<int, int>> virusPoint;
vector<pair<int, int>> wallPoint;


int getSafeArea(){

    int ret = 0;

    int labCopy[8][8];
    for(int i=0; i<labRow; i++){
        for(int j=0; j<labCol; j++){
            labCopy[i][j] = lab[i][j];
        }
    }

    for(int i=0; i<(int)wallPoint.size(); i++){
        labCopy[wallPoint[i].first][wallPoint[i].second] = WALL;
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visit(labRow, vector<bool>(labCol, false));
    for(int i=0; i<(int)virusPoint.size(); i++){
        q.push(virusPoint[i]);
        visit[virusPoint[i].first][virusPoint[i].second] = true;
    }

    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= labRow || nc < 0 || nc >= labCol) continue;
            if(visit[nr][nc] == true) continue;
            if(labCopy[nr][nc] == EMPTY){
                labCopy[nr][nc] = VIRUS;
                visit[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
    }

    for(int i=0; i<labRow; i++){
        for(int j=0; j<labCol; j++){
            if(labCopy[i][j] == EMPTY){
                ret += 1;
            }
        }
    }

    return ret;
}

void recur(int start){
    if((int)wallPoint.size() == 3){
        ans = std::max(ans, getSafeArea());
        return;
    }
    for(int i=start; i<labRow*labCol; i++){
        int row = i / labCol;
        int col = i % labCol;
        if(lab[row][col] != EMPTY) continue;
        wallPoint.push_back(make_pair(row, col));
        recur(i + 1);
        wallPoint.pop_back();
    }
}



int main(void){
    cin >> labRow >> labCol;
    for(int i=0; i<labRow; i++){
        for(int j=0; j<labCol; j++){
            cin >> lab[i][j];
            if(lab[i][j] == VIRUS){
                virusPoint.push_back(make_pair(i, j));
            }
        }
    }
    recur(0);
    cout << ans << '\n';
    return 0;
}

