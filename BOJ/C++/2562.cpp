#include <cstdio>

int main(){
    int arr[9];
    int MAX = 0;
    int idx;

    for(int i=0 ; i<9 ; i++){
        scanf("%d",&arr[i]);
        if(MAX < arr[i]){
            MAX = arr[i];
            idx = i;
        }
    }
    printf("%d\n%d\n",MAX,idx+1);
}
