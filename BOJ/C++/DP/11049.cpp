#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct MAT{
    int r;
    int c;
};
int main(){
    int n;
    scanf("%d",&n);
    MAT arr[501];
    int dp[501][501]={0,};
    for(int i=1 ; i<=n ; i++){
        scanf("%d%d",&arr[i].r,&arr[i].c);
    }

    for(int j=1 ; j<=n ; j++){
        for(int i=j-1 ; i>0 ; i--){
            dp[i][j] = INF;
            for(int k=i ; k<=j ; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i].r*arr[j].c*arr[k].c);
            }
        }
    }
    printf("%d\n",dp[1][n]);
}
