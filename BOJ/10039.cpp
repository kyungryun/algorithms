#include <cstdio>

int main(){
    int ans = 0;
    int a;
    for(int i=0 ; i<5 ; i++){
        scanf("%d",&a);
        if(a < 40) a = 40;
        ans += a;
    }
    printf("%d\n",ans/5);
}
