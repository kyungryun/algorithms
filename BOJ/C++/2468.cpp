#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int map[101][101];
int visited[101][101];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void dfs(int r, int c, int w){

    for(int i=0; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 || nr < n || nc >= 0 || nc < n){
            if(map[nr][nc] > w && !visited[nr][nc]){
                visited[nr][nc] = true;
                dfs(nr,nc,w);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int cnt;
    int ans = 1;
    for(int w=0 ; w<=100 ; w++){
        memset(visited,false,sizeof(visited));
        cnt = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(map[i][j] > w && !visited[i][j]){
                    visited[i][j] = true;
                    cnt++;
                    dfs(i,j,w);
                }
            }
        }
        ans = max(cnt, ans);
    }
    printf("%d\n",ans);
}
