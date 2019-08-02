// 다시 풀기

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int N,M;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int ans = 987654321;

void bfs(int (*map)[11]){
    queue<pair<int, pair<int, int>>>q;
    q.push(make_pair(0,make_pair(0,0)));
    int dist[11][11][20];
    memset(dist, -1, sizeof(dist));
    dist[0][0][0] = 0;
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int time = q.front().first;
        q.pop();

        if(r == N-1 && c == N-1){
            ans = min(ans, dist[N-1][N-1][0]);
            return;
        }
        bool flag = false;
        if(map[r][c] > 1 && time % map[r][c] != 0){
            int nt = (time+1)%map[r][c];
            if(dist[r][c][nt] == -1){
                dist[r][c][nt] = dist[r][c][time]+1;
                q.push(make_pair(nt,make_pair(r,c)));
            }
        }else{
            for(int i=0 ; i<4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= N || nc < 0 || nc >= N ) continue;
                if(map[nr][nc] > 1 && map[r][c] > 1) continue;

                if(map[nr][nc] >= 1){
                    int nt = (dist[r][c][time]+1) % map[nr][nc];
                    if(dist[nr][nc][nt] == -1){
                        dist[nr][nc][nt] = dist[r][c][time]+1;
                        q.push(make_pair(nt,make_pair(nr,nc)));
                    }
                }
            }

        }

    }
}
bool check(int r, int c, int (*map)[11]){
    int ridx = 0;
    int cidx = 0;

    for(int i=0 ; i<2 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(map[nr][nc] == 0) cidx++;
    }
    for(int i=2 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(map[nr][nc] == 0) ridx++;
    }
    if(ridx >= 1 && cidx >= 1) return false;

    return true;
}
int main(){
    int map[11][11];
    scanf("%d%d",&N,&M);

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(map[i][j] == 0 && check(i,j,map)){
                map[i][j] = M;
                bfs(map);
                map[i][j] = 0;
            }
        }
    }
    printf("%d\n",ans);
}
