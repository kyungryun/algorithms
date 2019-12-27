#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int map[1001][1001];
int visit[1001][1001];
int n,m,ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;
void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx >= 0 && xx< n && yy>= 0 && yy<m ){
                if(map[xx][yy] == 0 && visit[xx][yy] == -1){
                    q.push(make_pair(xx,yy));
                    visit[xx][yy] = visit[x][y] + 1;
                }
            }
        }
    }
}
int check(){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(map[i][j] == 0 && visit[i][j] == -1){
                return -1;
            }
        }
    }
    return ans;
}
int main(){

    scanf("%d%d",&m,&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&map[i][j]);
            visit[i][j] = -1;
            if(map[i][j] == 1) {
                q.push(make_pair(i,j));
                visit[i][j] = 0;
            }

        }
    }
    bfs();
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(visit[i][j] > ans){
                ans = visit[i][j];
            }
        }
    }
    
    printf("%d\n",check());
}
