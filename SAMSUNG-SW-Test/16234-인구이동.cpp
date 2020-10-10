#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mapSize;
int lowerLimit;
int upperLimit;
int map[50][50];
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int difference(const int x, const int y)
{
    return x < y ? y - x : x - y;
}

bool bfs(const int r, const int c, vector<vector<bool>>& check)
{

    int totalPopulation = 0;
    int totalArea = 0;
    
    check[r][c] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    vector<pair<int, int>> moved;

    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        totalArea += 1;
        totalPopulation += map[cr][cc];
        moved.push_back(make_pair(cr, cc));
        q.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= mapSize || nc < 0 || nc >=mapSize) continue;
            if(check[nr][nc] == true) continue;
            int dif = difference(map[nr][nc], map[cr][cc]);
            if(lowerLimit <= dif && dif <= upperLimit){
                check[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
    }

    int newPopulation = totalPopulation / totalArea;

    for(int i=0; i<(int)moved.size(); i++){
        map[moved[i].first][moved[i].second] = newPopulation;
    }

    return totalArea > 1 ? true : false;

}

bool migration()
{
    int ret = 0;
    vector<vector<bool>> check(mapSize, vector<bool>(mapSize, false));
    for(int i=0; i<mapSize; i++){
        for(int j=0; j<mapSize; j++){
            if(check[i][j] == false){
                ret += bfs(i, j, check);
            }
        }
    }
    return (bool)ret;
}

int main(void)
{
    cin >> mapSize >> lowerLimit >> upperLimit;
    for(int i=0; i<mapSize; i++){
        for(int j=0; j<mapSize; j++){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    while(true){
        bool res = migration();
        if(res == true){
            ans += 1;
        }else{
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}