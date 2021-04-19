#include <cstdio>
#include <algorithm>

using namespace std;

/*
    LIS 최장 증가 수열
*/
int main(){
    int n;
    int box[1001];
    int dp[1001] = {0,};
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)scanf("%d",&box[i]);
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        dp[i] = 1;
        for(int j=0 ; j<i ; j++){
            if(box[i] > box[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
            }
        }
        if(ans < dp[i]) ans = dp[i];
    }
    printf("%d\n",ans);
}
