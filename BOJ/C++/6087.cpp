#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int w,h;
char map[101][101];
int visited[101][101];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
int ans = 987654321;

void bfs(int sr, int sc, int er, int ec){
}
int main(){
    scanf("%d%d",&w,&h);
    for(int i=0 ; i<h ; i++){
        scanf("%s",map[i]);
    }
    int sr,sc,er,ec;
    int idx = 0;
    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            if(map[i][j] == 'C' && idx == 0){
                sr = i;
                sc = j;
                idx=1;
            }else if(map[i][j] == 'C' && idx == 1){
                er = i;
                ec = j;
            }
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    for(int i=0 ; i<4 ; i++){
        q.push(make_pair(make_pair(sr,sc),make_pair(i,0)));
    }
    memset(visited,-1,sizeof(visited));
    visited[sr][sc] = 0;

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            int ncnt = cnt;
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if(map[nr][nc] == '*')continue;
            if(i != dir) ncnt++;
            if(visited[nr][nc] >= ncnt || visited[nr][nc] == -1){
                visited[nr][nc] = ncnt;
                q.push(make_pair(make_pair(nr,nc),make_pair(i,ncnt)));
            }
        }

    }

    printf("%d\n",visited[er][ec]);
}
