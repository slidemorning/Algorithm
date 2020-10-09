#include <iostream>
#include <vector>
using namespace std;

#define EMPTY 0
#define HOUSE 1
#define CHICKEN 2
struct ChickenShop{
    int row;
    int col;
    bool live;
};
vector<struct ChickenShop> inputChickenShop;
int mapSize;
int numMaxChicken;
int map[51][51];
int ans = 50*50*13;


int distance(pair<int, int> p1, pair<int, int> p2)
{
    int dist = 0;
    dist += p1.first < p2.first ? p2.first - p1.first : p1.first - p2.first;
    dist += p1.second < p2.second ? p2.second - p1.second : p1.second - p2.second;
    return dist;
}

int getChickenDistance(int hr, int hc)
{
    int dist = 50*2;
    for(int i=0; i<(int)inputChickenShop.size(); i++){
        if(inputChickenShop[i].live == true){
            dist = min(distance({hr, hc}, {inputChickenShop[i].row, inputChickenShop[i].col}), dist);
        }
    }
    return dist;
}

int updateAns()
{
    int dist = 0;
    for(int i=1; i<=mapSize; i++){
        for(int j=1; j<=mapSize; j++){
            if(map[i][j] == HOUSE){
                dist += getChickenDistance(i, j);
            }
        }
    }
    return dist;
}

void recur(int start, int cnt)
{

    if(cnt > numMaxChicken){
        return;
    }

    if(cnt > 0){
        ans = min(ans, updateAns());
    }


    for(int i=start; i<(int)inputChickenShop.size(); i++){
        inputChickenShop[i].live = true;
        recur(i+1, cnt+1);
        inputChickenShop[i].live = false;
    }
}

int main(void)
{
    cin >> mapSize >> numMaxChicken;
    for(int i=1; i<=mapSize; i++){
        for(int j=1; j<=mapSize; j++){
            cin >> map[i][j];
            if(map[i][j] == CHICKEN){
                inputChickenShop.push_back({i, j, false});
            }
        }
    }
    recur(0, 0);
    cout << ans << '\n';
}