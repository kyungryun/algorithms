#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int y,x,a,b;
vector<pair<int, int>> map[102][102];
bool check[102][102];
int room[102][102];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int ans;
void bfs(int sr, int sc){
    bool visited[102][102];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(sr,sc));
    visited[sr][sc] = true;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nr > n || nc < 1 || nc > n) continue;
            if(room[nr][nc] == 1 && !visited[nr][nc]){
                if(map[nr][nc].size() > 0 && !check[nr][nc]){
                    for(int j=0 ; j<map[nr][nc].size() ; j++){
                        room[map[nr][nc][j].first][map[nr][nc][j].second] = 1;
                    }
                    check[nr][nc] = true;
                    bfs(1,1);
                }
                visited[nr][nc] = true;
                q.push(make_pair(nr,nc));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<m ; i++){
        scanf("%d%d%d%d",&y,&x,&a,&b);
        map[y][x].push_back(make_pair(a,b));
    }
    room[1][1] = 1;
    check[1][1] = 1;
    if(map[1][1].size() > 0){
        for(int i=0 ; i<map[1][1].size() ; i++){
            room[map[1][1][i].first][map[1][1][i].second] = 1;
        }
        bfs(1,1);
    }else{
        ans = 0;
    }


    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(room[i][j]) ans++;
        }
    }
    printf("%d\n",ans);
}
