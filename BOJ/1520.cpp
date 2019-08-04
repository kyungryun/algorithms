#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int N,M;
int map[501][501];
int dp[501][501];

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int dfs(int r, int c){
    if(r == 0 && c == 0) return 1;
    if(dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 0;
    for(int i=0 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
        if(map[r][c] < map[nr][nc]){
            dp[r][c] += dfs(nr,nc);
        }
    }
    return dp[r][c];
}
int main(){
    scanf("%d%d",&M,&N);

    for(int i=0 ; i<M ; i++){
        for(int j=0 ; j<N ; j++){
            scanf("%d",&map[i][j]);
            dp[i][j] = -1;
        }
    }
    printf("%d\n",dfs(M-1,N-1));
}
