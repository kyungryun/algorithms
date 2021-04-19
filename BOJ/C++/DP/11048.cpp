#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    int arr[1001][1001];
    int dp[1001][1001]={0,};
    int d[1001] ={0,};
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(i==0 && j==0) continue;
            if(i-1 < 0) dp[i][j] = arr[i][j] + dp[i][j-1];
            else if(j-1 < 0) dp[i][j] = arr[i][j] + dp[i-1][j];
            else dp[i][j] = arr[i][j] + max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    printf("%d\n",dp[n-1][m-1]);
}
