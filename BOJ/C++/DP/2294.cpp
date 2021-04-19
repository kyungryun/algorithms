#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    int coin[101];
    int dp[10001];
    scanf("%d%d",&n,&k);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&coin[i]);
    }
    for(int i=0 ; i<10001 ; i++) dp[i] = -1;
    dp[0] = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<=k ; j++){
            if(j-coin[i] >= 0 && dp[j-coin[i]] != -1){
                if(dp[j] == -1){
                    dp[j] = dp[j-coin[i]]+1;
                }else dp[j] = dp[j] > dp[j-coin[i]]+1 ? dp[j-coin[i]]+1 : dp[j];
            }
        }
    }
    printf("%d\n",dp[k]);
}
