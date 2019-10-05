#include <cstdio>

int main(){
    int arr[5];
    int sum = 0;
    for(int i=0 ; i<5 ; i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    for(int i=0 ; i<5 ; i++){
        for(int j=i+1 ; j<5 ; j++){
            if(arr[i] > arr[j]){
                arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
            }
        }
    }
    printf("%d\n",sum/5);
    printf("%d\n",arr[2]);

}
