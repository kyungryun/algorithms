#include <cstdio>

int main(){
    int sum;
    scanf("%d",&sum);
    int a;
    for(int i=0 ; i<9 ; i++){
        scanf("%d",&a);
        sum-=a;
    }
    printf("%d\n",sum);
}
