#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int arr[101][101];
    long long dp[101][101]={0,};

    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dp[0][0] = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int cur = arr[i][j];

            if(i != n-1 && i+cur < n) dp[i+cur][j] += dp[i][j];

            if(j != n-1 && j+cur < n) dp[i][j+cur] += dp[i][j];
        }
    }
    printf("%lld\n",dp[n-1][n-1]);
}
