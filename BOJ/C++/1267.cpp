#include <cstdio>

int main(){
    int n;
    int arr[21];
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    int y=0, m=0;
    for(int i=0 ; i<n ; i++){
        y += (arr[i]/30+1)*10;
        m += (arr[i]/60+1)*15;
    }
    if(y > m){
        printf("M %d\n",m);
    }else if(y == m){
        printf("Y M %d\n",y);
    }else{
        printf("Y %d\n",y);
    }
}
