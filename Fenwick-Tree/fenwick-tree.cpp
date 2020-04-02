
/*
    Fenwick Tree (Binary Indexed Tree, BIT)
    
    [ 이진수 A의 마지막 1의 위치 => (A & -A) ]
         A = 00000000 00000000 00000000 00001110 ( 14)
        -A = 11111111 11111111 11111111 11110010 (-14) (2's complement)
     A &-A = 00000000 00000000 00000000 00000010  ( 2)

    https://www.acmicpc.net/blog/view/21 
*/

#include <stdio.h>

const int LENGTH = 10;

// not use index 0
int tree[LENGTH + 1];

int sum(int index){
    int ret = 0;
    while(index > 0){
        ret += tree[index];
        index -= (index & -index);
    }
    return ret;
}

void update(int index, int diff){
    while(index <= LENGTH){
        tree[index] += diff;
        index += (index & -index);
    }
}

int getPrefixSum(int start, int end){
    return sum(end) - sum(start - 1);
}

int main(void){

    // [3, 6, 1, 8, 4, 9, 2, 1, 2, 7] 
    update(1, 3);
    update(2, 6);
    update(3, 1);
    update(4, 8);
    update(5, 4);
    update(6, 9);
    update(7, 2);
    update(8, 1);
    update(9, 2);
    update(10, 7);

    printf("%d\n", getPrefixSum(1, 10));

    update(3, -3);

    printf("%d\n", getPrefixSum(1, 10));

    return 0;
}