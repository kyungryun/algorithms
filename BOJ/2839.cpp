#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int cnt = 0;
    if(n%5 == 0){
        printf("%d\n",n/5);
    }else{
        while(1){
            n-=3;
            cnt++;
            if(n%5 == 0){
                printf("%d\n",n/5 + cnt);
                break;
            }else if(n == 0){
                printf("%d\n",cnt);
                break;
            }else if(n < 0){
                printf("-1\n");
                break;
            }
        }
    }
}
