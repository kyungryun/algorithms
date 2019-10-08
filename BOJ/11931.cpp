#include <cstdio>

int main(){
    int n;
    int arr[2000003]={0,};
    scanf("%d",&n);
    int num;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&num);
        arr[num+1000000] = 1;
    }
    for(int i=2000001 ; i>=0 ; i--){
        if(arr[i] == 1){
            printf("%d\n",i-1000000);
        }
    }
}
