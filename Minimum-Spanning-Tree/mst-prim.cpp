#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num_vertex;
int num_edge;
vector<pair<int, int>> adj[1001];

long long prim(const int start){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<bool> select(1001);

    fill(select.begin(), select.end(), false);

    select[start] = true;
    for(auto p : adj[start]){
        q.push(p);
    }

    long long ret = 0;
    while(!q.empty()){
        int curr = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(select[curr]) continue;
        select[curr] = true;
        ret += cost;
        for(auto next : adj[curr]){
            q.push(next);
        }
    }
    return ret;
}

int main(void){
    cin >> num_vertex >> num_edge;
    for(int i=0; i<num_edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(cost, to));
        adj[to].push_back(make_pair(cost, from));
    }
    cout << prim(1) << '\n';
    return 0;
}