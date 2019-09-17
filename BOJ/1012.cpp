#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int t,n,m,k;
int map[51][51];
bool visited[51][51];
int x,y;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int cnt;
int main(){
    scanf("%d",&t);
    for(int T=1 ; T<=t ; T++){
        cnt = 0;
        scanf("%d%d%d",&m,&n,&k);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
        for(int i=0 ; i<k ; i++){
            scanf("%d%d",&x,&y);
            map[y][x] = 1;
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if(visited[r][c]) continue;
                        visited[r][c] = true;
                        for(int k=0 ; k<4 ; k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if(nr < 0 || nc < 0 || nr >= n || nc>= m || visited[nr][nc])continue;
                            if(map[nr][nc] == 1){
                                q.push(make_pair(nr,nc));
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
}
