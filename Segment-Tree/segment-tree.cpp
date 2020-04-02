/*
    Segment Tree
    init() - Initialize Segment Tree (Build Tree)
    sum() - 
    update() -
*/

#include <iostream>


const int LENGTH = 10;

int a[LENGTH] = {2, 5, 3, 1, 9, 7, 4, 6, 8, 5};

int tree[4*LENGTH];

// build sgement tree
// index of root node is 0
// left child -> index * 2 + 1
// right child -> index * 2 + 2
int init(int index, int start, int end){
    if(start == end){
        tree[index] = a[start];
    }else{
        int mid = (start + end) / 2;
        tree[index] = init(index*2 + 1, start, mid) + init(index*2 + 2, mid+1, end);
    }
    return tree[index];
}

// 탐색범위 (호출된 상태에서의 탐색범위) : [start, end]
// 구하려는 합의 범위 (구간합의 범위) : [left, right]
// 현재 segment tree 의 index : index
int sum(int index, int start, int end, int left, int right){
    if(left > end || right < start) return 0;

    //     [left         ~         right]
    // [  else  ][start ~     end][   else ]
    else if(left <= start && end <= right) return tree[index];
    else{
        int mid = (start+end) / 2;
        return sum(index*2 + 1, start, mid, left, right) + sum(index*2 + 2, mid+1, end, left, right);
        // mid 로 나누어서 호출하는 순간 겹치는 문제는 없으므로 구간이 만족하는지 확인할때
        // left <= start && end <= right 로 해결하면 된다.
        // 즉 left <= start && end <= right 를 만족하는 sub tree 들이
        // 겹치지않고 merge 되어 결과값을 return 하게 된다.
        // 그림을 그려보면 쉽게 이해됨
    }
}

void update(int target_index, int diff, int index, int start, int end){
    
    if(target_index < start || target_index > end) return;


    tree[index] += diff;
    
    if(start == end) return; // leaf node case

    int mid = (start+end) / 2;
    update(target_index, diff, index*2 + 1, start, mid);
    update(target_index, diff, index*2 + 2, mid+1, end);
}

int main(void){

    init(0, 0, LENGTH-1);
    std::cout << sum(0, 0, LENGTH-1, 2, 6) << '\n';
    update(4, 10, 0, 0, LENGTH-1);
    std::cout << sum(0, 0, LENGTH-1, 2, 6) << '\n';
    return 0;
}