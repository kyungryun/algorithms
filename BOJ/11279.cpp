#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int op;
int arr[100001];
int idx = 0;
void push(int x){
    idx++;
    arr[idx] = x;
    int child = idx;
    int parent = child/2;
    while(child > 1 && arr[parent] < arr[child]){
        int t = arr[parent];
        arr[parent] = arr[child];
        arr[child] = t;
        child=parent;
        parent=child/2;
    }
}
int pop(){
    int num = arr[1];
    arr[1] = arr[idx];
    if(idx != 0) idx--;
    else return 0;
    int parent = 1;
    int child = parent*2;
    if(child + 1 <= idx){
        if(arr[child] <= arr[child+1]) child++;
    }
    while(child <= idx && arr[child] > arr[parent]){
        int t = arr[child];
        arr[child] = arr[parent];
        arr[parent] = t;
        parent = child;
        child *= 2;
        if(child + 1 <= idx){
            if(arr[child] <= arr[child+1]) child++;
        }
    }
    return num;
}
int main(){
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        scanf("%d",&op);
        if(op != 0){
            push(op);
        }else printf("%d\n",pop());
    }
}
