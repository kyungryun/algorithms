#include <cstdio>

int n;
int buf[1001];

void merge(int *arr, int len){
    if(len < 2) return;

    int mid = len/2;
    int i=0,j=mid,k=0;

    merge(arr, mid);
    merge(arr+mid, len-mid);
    while(i<mid && j<len){
        if(arr[i] < arr[j]) buf[k++] = arr[i++];
        else buf[k++] = arr[j++];
    }
    while(i<mid) buf[k++] = arr[i++];
    while(j<len) buf[k++] = arr[j++];

    for(int i=0 ; i<len ; i++){
        arr[i] = buf[i];
    }
}

int main(){
    int arr[1001];
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    merge(arr, n);
    for(int i=0 ; i<n ; i++){
        printf("%d\n",arr[i]);
    }
}
