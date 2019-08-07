#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int map[1001][1001];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int ans = 987654321;
int cnt;
bool visited[1001][1001][2];
void bfs(){
    queue<pair<pair<int, int>, pair<int, int>>>q;
    q.push(make_pair(make_pair(1,1), make_pair(1,0)));
    visited[1][1][0] = true;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second.first;
        int wall = q.front().second.second;
        q.pop();
        if(r == n && c == m){
            ans = min(ans, cnt);
            break;
        }
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 1 && nr <= n && nc >= 1 && nc <= m){
                if(map[nr][nc] == 1 && wall == 0){
                    visited[nr][nc][wall+1] = true;
                    q.push(make_pair(make_pair(nr,nc),make_pair(cnt+1,wall+1)));
                }else if(map[nr][nc] == 0 && !visited[nr][nc][wall]){
                    visited[nr][nc][wall] = true;
                    q.push(make_pair(make_pair(nr,nc),make_pair(cnt+1,wall)));
                }
            }


        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    bfs();
    printf("%d\n",ans == 987654321 ? -1 : ans);
}
