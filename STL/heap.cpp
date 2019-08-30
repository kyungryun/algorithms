#include <cstdio>
#include <algorithm>
#include <windows.h>

using namespace std;

struct MY_HEAP{
    int heap_size;
    int heap[10000];

    MY_HEAP(){
        heap_size = 0;
    }
    void push(int data){
        int target = heap_size + 1;
        while(target != 1 && heap[target/2] < data){
            heap[target] = heap[target/2];
            target /= 2;
        }
        heap[target] = data;
        heap_size++;
    }
    void pop(){
        int parent = 1;
        int child = 2;
        int temp = heap[heap_size];
        while(child < heap_size){
            if(child + 1 < heap_size && heap[child] < heap[child+1]) child++;
            if(temp >= heap[child]) break;
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = temp;
        heap_size--;
    }
    int size(){
        return heap_size;
    }
    int top(){
        return heap[1];
    }
};

int comp(int a, int b){
    return a > b;
}
int main(){
    int a[10000];
    MY_HEAP heap;
    for(int i=0 ; i<10 ; i++){
        a[i] = rand()%10;
    }
    for(int i=0 ; i<10 ; i++){
        heap.push(a[i]);
    }
    sort(a, a+10, comp);
    for(int i=0 ; i<10 ; i++){
        if(a[i] != heap.top()) printf("%d %d\n",a[i], heap.top());
        heap.pop();
    }
    printf("finish\n");

}
