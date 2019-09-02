#include <cstdio>

const int MAX_SIZE = 500000;
int buff[MAX_SIZE];
int array[MAX_SIZE];

void merge(int *arr, int len){
    if(len < 2) return;
    int i,j,k;
    int mid = len/2;
    i=0,j=mid,k=0;


    merge(arr, mid);
    merge(arr+mid, len-mid);

    while(i < mid && j < len){
        if(arr[i] < arr[j]) buff[k++] = arr[i++];
        else buff[k++] = arr[j++];
    }
    while(i<mid) buff[k++] = arr[i++];
    while(j<len) buff[k++] = arr[j++];

    for(int i=0 ; i<len ; i++){
        arr[i] = buff[i];
    }
}

void qsort(int *arr, int left, int right){
    if(left >= right) return;
    int start = left - 1;
    int end = right + 1;
    int mid = arr[(start+end)/2];
    while(1){
        while(arr[++start] < mid);
        while(arr[--end] > mid);

        if(start >= end) break;

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    qsort(arr, left, start-1);
    qsort(arr, end+1, right);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&array[i]);
    }
    qsort(array, 0,n-1);
    for(int i=0 ; i<n ; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
