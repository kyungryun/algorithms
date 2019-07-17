#include <cstdio>

using namespace std;

int map[17][17];
int N;
int dr[3] = {0,1,1};
int dc[3] = {1,1,0};
int cnt;
int dp[17][17][3];
void dfs(int hr, int hc, int tr, int tc, int d){
    if(hr == N && hc == N) {
        cnt++;
        return;
    }
    for(int i=0 ; i<3 ; i++){
        if((d == 0 && i == 2) || (d == 2 && i == 0)) continue;
        int nr = hr + dr[i];
        int nc = hc + dc[i];
        if(nr < 1 || nr > N || nc < 1 || nc > N || map[nr][nc] == 1) continue;
        if(i == 1){
            if(map[nr-1][nc] == 1 || map[nr][nc-1] == 1) continue;
        }
        dfs(nr, nc, hr, hc, i);
    }
}
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
    //dfs(1, 2, 1, 1, 0);
    DP();
    cnt = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    printf("%d\n",cnt);
}
