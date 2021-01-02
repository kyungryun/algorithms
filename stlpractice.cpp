#include <cstdio>
#define swap(a,b) a^=b^=a^=b


int heap[100000];
int heap_size;

void push(int data){
    int cur = heap_size+1;
    while(cur != 1 && heap[cur/2] < data){
        heap[cur] = heap[cur/2];
        cur/=2;
    }
    heap[cur] = data;
    heap_size++;
}

void pop(){
    int parent = 1;
    int child = 2;
    int temp = heap[heap_size];
    while(child < heap_size){
        if(child+1 < heap_size && heap[child] < heap[child+1]) child++;
        if(temp>=heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *=2;
    }
    heap[parent] = temp;
    heap_size--;
}
