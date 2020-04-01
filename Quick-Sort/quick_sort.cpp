#include <iostream>
using namespace std;

int n;
int a[1000000];

void qsort(int start, int end){
    if(start >= end) return;
    int pivot = a[(start+end)/2];
    int left = start;
    int right = end;
    while(left <= right)
    {
        while(a[left] < pivot) left++;
        while(a[right] > pivot) right--;
        if(left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    qsort(start, right);
    qsort(left, end);
}

int main(void)
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", a+i);
    }
    qsort(0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}