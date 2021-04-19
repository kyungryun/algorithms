#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int d[1001][1001][3];
int N,M;
int dr[3] = {0,0,1};
int dc[3] = {1,-1,0};
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    d[0][0][0] = map[0][0];
    d[0][0][1] = map[0][0];
    d[0][0][2] = map[0][0];
    for(int i=1 ; i<M ; i++){
        d[0][i][0] = map[0][i] + d[0][i-1][0];
        d[0][i][1] = map[0][i] + d[0][i-1][1];
        d[0][i][2] = map[0][i] + d[0][i-1][2];
    }
    for(int i=1 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            if(j == 0) d[i][j][0] = map[i][j] + max(d[i-1][j][0],d[i-1][j][2]);
            else d[i][j][0] = map[i][j] + max(d[i-1][j][0],max(d[i-1][j][1],d[i-1][j][2]));
        }
        for(int j=0 ; j<M ; j++){
            if(j == 0) d[i][j][1] = max(d[i-1][j][0],d[i-1][j][2]) + map[i][j];
            else d[i][j][1] = map[i][j] + max(d[i][j-1][0], d[i][j-1][1]);
        }
        for(int j=M-1 ; j>=0 ; j--){
            if(j == M-1) d[i][j][2] = max(d[i-1][j][0],d[i-1][j][1]) + map[i][j];
            else d[i][j][2] = map[i][j] + max(d[i][j+1][0],d[i][j+1][2]);
        }
    }
    printf("%d\n",max(d[N-1][M-1][0],max(d[N-1][M-1][1],d[N-1][M-1][2])));
}
