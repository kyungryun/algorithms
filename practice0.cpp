#include <cstdio>

int heap[100000];
int heap_size;

void push(int data){
    int target = heap_size+1;
    while(target != 1 && heap[target/2] < data){
        heap[target] = heap[target/2];
        target/=2;
    }
    heap[target] = data;
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
        child*=2;
    }
    heap[parent] = temp;
    heap_size--;
}

int main(){
    int arr[10] = {1,3,2,5,5,2,7,5,8,11};

    for(int i=0 ; i<10 ; i++) push(arr[i]);

    for(int i=0 ; i<10 ; i++){
        printf("%d\n",heap[1]);
        pop();
    }
}
