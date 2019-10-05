#include <cstdio>

int main(){
    int arr[3];
    int MAX = 0;
    for(int i=0 ; i<3 ; i++){
        scanf("%d",&arr[i]);
        if(MAX < arr[i]) MAX = arr[i];
    }

    if(arr[0] == arr[1] && arr[0] == arr[2]){
        printf("%d\n",10000 + arr[0]*1000);
    }else if(arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2]){
        printf("%d\n",MAX*100);
    }else{
        if(arr[0] == arr[1] || arr[0] == arr[2]) printf("%d\n",1000 + arr[0]*100);
        else printf("%d\n",1000 +arr[1]*100);
    }

}
