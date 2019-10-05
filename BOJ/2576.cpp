#include <cstdio>

int main(){
    int arr[7];
    int MIN =101;
    int idx;
    int sum = 0;
    for(int i=0 ; i<7 ; i++){
        scanf("%d",&arr[i]);
        if(arr[i]%2 == 1){
            sum += arr[i];
            if(MIN > arr[i]){
                MIN = arr[i];
            }
        }
    }
    if(sum == 0){
        printf("-1\n");
    }else{
        printf("%d\n%d\n",sum,MIN);
    }
}
