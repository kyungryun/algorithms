#include <cstdio>

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    int res = m;
    int ans = 0;
    while(n--){
        int in,out;
        scanf("%d%d",&in,&out);
        res += (in-out);
        if(res < 0){
            ans = 0;
            break;
        }
        if(res > ans) ans = res;
    }
    printf("%d\n",ans);
}
