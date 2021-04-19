#include <cstdio>


int main(){
    int n;
    int arr[2000003]={0,};
    scanf("%d",&n);
    int num;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&num);
        arr[num+1000000]++;
    }
    for(int i=0 ; i<2000001 ; i++){
        for(int j=0 ; j<arr[i] ; j++){
            printf("%d\n",i-1000000);
        }
    }
}
