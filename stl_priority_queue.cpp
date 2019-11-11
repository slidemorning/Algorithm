#include <iostream>
#include <queue>
typedef std::pair<int, int> pii;

std::priority_queue<int> pq; // default : max heap
std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
std::priority_queue<int, std::vector<int>, std::less<int>> max_pq;
std::priority_queue<pii, std::vector<pii>, std::less<pii>> max_pii_pq;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> min_pii_pq;

int main(void){
    // time complexibility of method 'push' : O(logN)
    pq.push(5);
    pq.push(1);
    pq.push(9);
    pq.push(3);
    pq.push(4);
    while(!pq.empty()){
        std::cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}

/*
    std output
*/
