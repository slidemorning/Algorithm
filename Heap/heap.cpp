#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define HEAP_SIZE 256
#define ARRAY_SIZE 100

int pow_2(int e)
{
    int ret=1;
    for(int i=0; i<e; i++)
    {
        ret *= 2;
    }
    return ret;
}

class MaxHeap
{
    public:
    
    int heap[HEAP_SIZE];
    int heap_count;
    
    MaxHeap() {heap_count = 0;}
    
    int size()
    {
        return this->heap_count;
    }

    void print_heap()
    {
        if(this->size() == 0)
        {
            printf("heap is empty ...\n");
            return;
        }
        int cur = 1;
        int depth = 0;
        while(cur <= heap_count)
        {
            printf("-----depth[%d]-----\n", depth);
            for(int i=0; i<pow_2(depth); i++)
            {
                printf("%d ", heap[cur++]);
                if(cur > heap_count) break;
             }
            printf("\n");
            depth++;
        }
        printf("------------------\n");
    }

    void _swap_(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void push(int data)
    {
        printf("push %d\n", data);
        
        
        heap[++heap_count] = data;
        int child = heap_count;
        int parent = child / 2;
        while(child > 1 && heap[parent] < heap[child])
        {
            swap(heap[parent], heap[child]);
            child = parent;
            parent = child/2;
        }
        
    }

    int pop()
    {
        int ret = heap[1];
        swap(heap[1], heap[heap_count]);
        heap_count--;

        int parent = 1;
        int child = parent * 2;
        if(child+1 <= heap_count)
        {
            child = heap[child] > heap[child+1] ? child : child+1;
        }
        while(child <= heap_count && heap[parent] < heap[child])
        {
            swap(heap[parent], heap[child]);
            parent = child;
            child = child*2;
            if(child+1 <= heap_count)
            {
                child = heap[child] > heap[child+1] ? child : child+1;
            }
        }
        printf("pop %d\n", ret);
        return ret;        
    }
};

int main()
{
    MaxHeap mh = MaxHeap();
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        arr[i] = rand()%200 + 1;
    }
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        mh.push(arr[i]);
    }
    mh.print_heap();
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        mh.pop();
    }
    printf("\n");
    return 0;
}