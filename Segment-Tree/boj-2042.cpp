// http://www.acmicpc.net/problem/2042
// Segment Tree - Prefix Sum
#include <iostream>
#include <vector>

// 1 <= n <= 1000000
int n, m, k;
std::vector<long long> a; 
std::vector<long long> st;

long long init(int index, int start, int end){
    if(start == end) st[index] = a[start];
    else{
        int mid = (start + end) / 2;
        st[index] = init(index*2 + 1, start, mid) + init(index*2 + 2, mid+1, end);
    }
    return st[index];
}

long long sum(int index, int start, int end, int left, int right){
    if(end < left || start > right) return 0;
    else if(left <= start && end <= right) return st[index];
    else{
        int mid = (start + end) / 2;
        return sum(index*2 + 1, start, mid, left, right) + sum(index*2 + 2, mid+1, end, left, right);
    }
}

void update(int target_index, long long diff, int index, int start, int end){
    
    if(target_index < start || target_index > end) return;

    st[index] += diff;

    if(start == end) return;

    int mid = (start + end) / 2;
    update(target_index, diff, index*2 + 1, start, mid);
    update(target_index, diff, index*2 + 2, mid+1, end);
}

int main(void){

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> m >> k;
    
    a.resize(n);
    st.resize(n*4);

    for(int i=0; i<n; i++){
        std::cin >> a[i];
    }

    init(0, 0, n-1);

    // query
    for(int i=0; i<m+k; i++){
        int cmd, b, c;
        std:: cin >> cmd >> b >> c;
        if(cmd == 1){
            // b-1 번째 수를 c 로 update 
            long long prev = a[b-1];
            a[b-1] = c;
            update(b-1, a[b-1]-prev, 0, 0, n-1);
        }else{
            // b-1 번째 에서 c-1 까지 구간합
            std::cout << sum(0, 0, n-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}
