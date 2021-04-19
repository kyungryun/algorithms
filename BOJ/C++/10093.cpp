#include <iostream>


int main(){
    long long a,b;

    scanf("%lld%lld",&a,&b);
    if(a>b){
        printf("%lld\n",a-b-1);
        while(b<a-1){
            printf("%lld ",++b);
        }
        printf("\n");
    }else if(a == b){
        printf("0\n");
    }else{
        printf("%lld\n",b-a-1);
        while(a<b-1){
            printf("%lld ",++a);
        }
        printf("\n");
    }

}
