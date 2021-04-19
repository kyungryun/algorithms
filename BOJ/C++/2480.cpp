#include <cstdio>

int main(){
    int arr[3];
    int MAX = 0, ans = 0;;
    for(int i=0 ; i<3 ; i++){
        scanf("%d",&arr[i]);
        if(MAX < arr[i]) MAX = arr[i];
    }
    if(arr[0] == arr[1] && arr[0] == arr[2]) ans = 10000 + arr[0]*1000;
    else if(arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2]) ans = MAX*100;
    else{
        if(arr[0] == arr[1] || arr[0] == arr[2]) ans = 1000 + arr[0]*100;
        else ans = 1000 + arr[1]*100;
    }
    printf("%d\n",ans);
}
