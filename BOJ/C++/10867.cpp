#include <cstdio>

int n;
int arr[2001]={0,};
int main(){
    scanf("%d",&n);
    int num;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&num);
        arr[num+1000] = 1;
    }
    for(int i=0 ; i<2001 ; i++){
        if(arr[i] == 1){
            printf("%d ",i-1000);
        }
    }
    printf("\n");
}
