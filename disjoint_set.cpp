#include <iostream>

int n, m;
int disjoint[1000000+1];

int find(int vertex){
    if(disjoint[vertex] == vertex) return vertex;
    return disjoint[vertex] = find(disjoint[vertex]);
}

void merge(int v1, int v2){
    int p1 = find(v1);
    int p2 = find(v2);
    if(p1 == p2) return;
    // union 
    disjoint[p2] = p1;
}

int main(void){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    for(int i=0; i<=n; i++){
        disjoint[i] = i;
    }
    for(int i=0; i<m; i++){
        int op, v1, v2;
        std::cin >> op >> v1 >> v2;
        if(op == 0){
            merge(v1, v2);
        }else{
            if(find(v1) == find(v2)) std::cout << "yes" << '\n';
            else std::cout << "no" << '\n';
        }
    }
    return 0;
}
