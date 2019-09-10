#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int map[501][501];
int dr[4] = {0,0,1,-1};
int dc[4]  ={1,-1,0,0};
bool visited[501][501];
int ans;
void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(r,c));
    visited[r][c] = true;
    int cnt = 1;
    while(!q.empty()){
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int nr = rr + dr[i];
            int nc = cc + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(!visited[nr][nc] && map[nr][nc] == 1){
                visited[nr][nc] = true;
                cnt++;
                q.push(make_pair(nr,nc));
            }
        }
    }
    ans = max(ans, cnt);
}
int main(){
    scanf("%d%d",&n,&m);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int idx = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!visited[i][j] && map[i][j] == 1){
                bfs(i,j);
                idx++;
            }
        }
    }
    printf("%d\n%d\n",idx,ans);
}
