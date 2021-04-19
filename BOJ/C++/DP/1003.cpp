#include <cstdio>

/*
    fibo(n)  0 = fibo(n-1), 1 = fibo(n);
*/
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int dp[42] = {0,1,0,};
        scanf("%d",&n);
        for(int i=2 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        if(n == 0 ) printf("1 0\n");
        else printf("%d %d\n",dp[n-1], dp[n]);
    }
}
