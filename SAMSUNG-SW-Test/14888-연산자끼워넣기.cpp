#include <iostream>
#include <vector>
using namespace std;

const int ADD = 0;
const int SUB = 1;
const int MUL = 2;
const int DIV = 3;

int n, num[11], numOp[4];
int ansMax = -2e9;
int ansMin = 2e9;
int call = 0;

vector<int> opOrder;

void debug_put(int op){
    if(op == ADD) cout << "ADD ";
    else if(op == SUB) cout << "SUB ";
    else if(op == MUL) cout << "MUL ";
    else cout << "DIV ";
}

int calculate(){
    int ret = num[0];
    for(int i=0; i<n-1; i++){
        if(opOrder[i] == ADD){
            ret += num[i+1];
        }else if(opOrder[i] == SUB){
            ret -= num[i+1];
        }else if(opOrder[i] == MUL){
            ret *= num[i+1];
        }else{
            ret /= num[i+1];
        }
    }
    return ret;
}

void recur(){
    if(opOrder.size() == n-1){
        int res = calculate();
        ansMax = max(res, ansMax);
        ansMin = min(res, ansMin);
        return;
    }
    for(int i=0; i<4; i++){
        if(numOp[i] <= 0) continue;
        numOp[i]--;
        opOrder.push_back(i);
        recur();
        opOrder.pop_back();
        numOp[i]++;
    }
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    for(int i=0; i<4; i++){
        cin >> numOp[i];
    }
    recur();
    cout << ansMax << '\n';
    cout << ansMin << '\n';
    return 0;
}