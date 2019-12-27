#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];
int visit[101][101];
int n,m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans[25*25];
void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));

    visit[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(x == n && y == m) break;
        for(int i=0 ; i<4 ; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx >= 0 && xx<= n && yy>= 0 && yy<=m ){
                if(map[xx][yy] == 1 && visit[xx][yy] == 0){
                    q.push(make_pair(xx,yy));
                    visit[xx][yy] = visit[x][y] + 1;
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
    bfs(1, 1);
    printf("%d\n",visit[n][m]);
}
