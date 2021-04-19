#include <cstdio>

using namespace std;

int map[33][33];
int N;
int dr[3] = {0,1,1};
int dc[3] = {1,1,0};
long long cnt;
long long dp[33][33][3];
void DP(){
    dp[1][2][0] = 1;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            if(dp[i][j][0]){
                if(j<N && !map[i][j+1]) dp[i][j+1][0] += dp[i][j][0];
                if(j<N && i<N && (map[i][j+1] + map[i+1][j] + map[i+1][j+1]) == 0){
                    dp[i+1][j+1][2] += dp[i][j][0];
                }
            }
            if(dp[i][j][1]){
                if(i<N && !map[i+1][j]) dp[i+1][j][1] += dp[i][j][1];
                if(i<N && j<N && (map[i][j+1] + map[i+1][j] + map[i+1][j+1]) == 0){
                    dp[i+1][j+1][2] += dp[i][j][1];
                }
            }
            if(dp[i][j][2]){
                if(j<N && !map[i][j+1]) dp[i][j+1][0] += dp[i][j][2];
                if(i<N && !map[i+1][j]) dp[i+1][j][1] += dp[i][j][2];
                if(i<N && j<N && (map[i][j+1] + map[i+1][j] + map[i+1][j+1]) == 0){
                    dp[i+1][j+1][2] += dp[i][j][2];
                }
            }
        }
    }
}
int main(){
    scanf("%d",&N);
    cnt = 0;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    DP();
    cnt = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    printf("%lld\n",cnt);
}
