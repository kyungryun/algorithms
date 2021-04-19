
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int map[51][51];
int group[51][51];
int roomSize[2501];
int dr[4] = {0,-1,0,1};
int dc[4] = {-1,0,1,0};
void bfs(int r, int c, int idx){
    queue<pair<int, int>> q;
    q.push(make_pair(r,c));
    bool visited[51][51]={false,};
    visited[r][c] = true;
    group[r][c] = idx;
    roomSize[idx] = 1;
    while(!q.empty()){
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            if(!(map[rr][cc] & 1<<i)){
                int nr = rr + dr[i];
                int nc = cc + dc[i];

                if(nr < 0 || nr >=m || nc < 0 || nc >=n || visited[nr][nc]) continue;
                group[nr][nc] = idx;
                roomSize[idx]++;
                visited[nr][nc] = true;
                q.push(make_pair(nr,nc));
            }
        }
    }
}
int maxRoom(){
    int MAX = -1;
    for(int i=0 ; i<m*n ; i++){
        MAX = max(MAX, roomSize[i]);
    }
    return MAX;
}
int main(){
    scanf("%d%d",&n,&m);

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int idx = 0;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(group[i][j] == 0){
                bfs(i,j,++idx);
            }
        }
    }
    int MAX = -1;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<4 ; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(group[nr][nc] != group[i][j]){
                        //printf("%d %d %d %d\n", nr, nc, i,j);
                        //printf("%d %d\n",roomSize[group[i][j]], roomSize[group[nr][nc]]);
                        MAX = max(MAX,(roomSize[group[i][j]] + roomSize[group[nr][nc]]));
                    }
                }
            }
        }
    }
    printf("%d\n%d\n%d\n",idx,maxRoom(), MAX);
}
