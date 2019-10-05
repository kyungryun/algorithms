#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);

    if(n%400 == 0 || (n%4 == 0 && n%100 != 0)){
        printf("1\n");
    }else{
        printf("0\n");
    }
}
