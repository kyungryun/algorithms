#include <cstdio>

const int INF = 987654321;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int chapter;
        int dp[501][501] = {0,};
        int pSum[501] = {0,};
        int num;
        scanf("%d",&chapter);
        for(int i=1 ; i<=chapter ; i++){
            scanf("%d",&num);
            pSum[i] = pSum[i-1] + num;
        }

        for(int j=2 ; j <= chapter ; j++){
            for(int i=j-1 ; i>0 ; i--){
                dp[i][j] = INF;
                for(int k=i ; k<=j ; k++){
                    dp[i][j] = dp[i][j] > dp[i][k] + dp[k+1][j] ? dp[i][k] + dp[k+1][j] : dp[i][j];
                }
                dp[i][j] += pSum[j] - pSum[i-1];
            }
        }

        printf("%d\n",dp[1][chapter]);
    }
}
