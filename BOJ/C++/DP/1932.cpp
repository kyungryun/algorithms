#include <cstdio>

int main(){
    int n;
    int arr[501][501];
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<i+1 ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int dp[501][501] = {0,};
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][0];
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            if(j == 0) dp[i][j] = arr[i][j] + dp[i-1][j];
            else if(j+1 > i) dp[i][j] = arr[i][j] + dp[i-1][j-1];
            else dp[i][j] = arr[i][j] + (dp[i-1][j] > dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1]);
        }
    }
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        if(ans < dp[n-1][i]) ans = dp[n-1][i];
    }
    printf("%d\n",ans);
}
