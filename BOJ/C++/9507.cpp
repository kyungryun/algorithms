#include <cstdio>

using namespace std;

int main(){
    int t,n;
    long long dp[68];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
        for(int i=4 ; i<=n ; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
        printf("%lld\n",dp[n]);
    }
}