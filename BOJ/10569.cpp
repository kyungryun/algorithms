#include <cstdio>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int v,e;
        scanf("%d%d",&v,&e);
        printf("%d\n",e-v+2);
    }
}
