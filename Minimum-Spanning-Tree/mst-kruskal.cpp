/*
    https://www.acmicpc.net/problem/1922
    Kruskal Algorithm
*/
#include <iostream>
#include <algorithm>

struct Edge{
    int from;
    int to;
    int cost;
};
int n, m;
int disjoint[1001];
struct Edge edge[100000];

bool compare(struct Edge e1, struct Edge e2){
    // https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings
    // https://en.cppreference.com/w/cpp/named_req/Compare
    // if e1.cost == e2.cost then, return false.
    return e1.cost < e2.cost;
}

int find(int vertex){
    if(disjoint[vertex] == vertex) return vertex;
    return disjoint[vertex] = find(disjoint[vertex]);
}

bool merge(int v1, int v2){
    int p1 = find(v1);
    int p2 = find(v2);
    if(p1 == p2) return false;
    disjoint[p2] = p1;
    return true;
}

int main(void){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    for(int i=0; i<m; i++){
        std::cin >> edge[i].from >> edge[i].to >> edge[i].cost;
    }
    std::sort(edge, edge+m, compare);
    for(int i=0; i<=n; i++){
        disjoint[i] = i;
    }
    int ans = 0;
    int edge_cnt = 0;
    for(int i=0; i<m; i++){
        if(merge(edge[i].from, edge[i].to)){
            ans += edge[i].cost;
            edge_cnt += 1;
            if(edge_cnt == n-1) break;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
