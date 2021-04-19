#include <cstdio>

/*
    dp[i][j] = (0,0) ~ (i,j) 합
*/
int main(){
    int n,m,k;
    int num;
    int dp[302][302] = {0,};
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            scanf("%d",&num);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num;
        }
    }
    scanf("%d",&k);

    for(int i=0 ; i<k ; i++){
        int y1,y2,x1,x2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        printf("%d\n",dp[y2][x2]-dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1]);
    }
}
