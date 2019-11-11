#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef std::pair<int, int> P;

const int INF = 3000001;
int v, e;
int start;
int dist[20000+1];
bool visit[20000+1];
std::vector<std::vector<P>> adj;

void dijkstra(int start){
    
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    std::fill(dist, dist+v+1, INF);

    dist[start] = 0;
    pq.push(P(0, start));
    
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        if(visit[curr]) continue;
        visit[curr] = true;
        for(auto p : adj[curr]){
            int next = p.first;
            int weight = p.second;
            if(dist[next] > dist[curr] + weight){
                dist[next] = dist[curr] + weight;
                pq.push(P(dist[next], next));
            }
        }
    }

}

int main(void){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> v >> e >> start;
    adj.resize(v+1);
    for(int i=0; i<e; i++){
        int from, to, weight;
        std::cin >> from >> to >> weight;
        adj[from].push_back(P(to, weight));
    }
    dijkstra(start);
    for(int i=1; i<=v; i++){
        if(dist[i] == INF) std::cout << "INF" << '\n';
        else std::cout << dist[i] << '\n';
    }
    return 0;
}