#include <cstdio>
#include <algorithm>

using namespace std;

int dr[4] = {-1,1,1,-1};
int dc[4] = {-1,-1,1,1};
int n;
int map[11][11];
int cmap[11][11];

bool visited[101];
int ans[2];
bool check(int r, int c){
    for(int i=0 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        int pos = nr*n + nc;
        for(int j=1 ; j<n ; j++){
            if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                if(visited[pos]) return false;
            }
            nr += dr[i];
            nc += dc[i];
            pos = nr*n + nc;
        }
    }
    return true;
}
void dfs(int pos, int cnt, int color){
    if(ans[color] < cnt){
        ans[color] = cnt;
    }
    for(int i=pos+1 ; i<n*n ; i++){
        int r = i/n;
        int c = i%n;

        if(cmap[r][c] != color){
            continue;
         }
        if(map[r][c] == 1){
            if(check(r,c)){
                visited[i] = true;
                dfs(i, cnt+1, color);
            }

        }
    }
    if(pos == -1) return;
    visited[pos] = false;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1){
                if((i+j)%2 == 0){
                    cmap[i][j] = 1;
                }else cmap[i][j] = 0;
            }
        }
    }

    dfs(-1,0,0);
    dfs(-1,0,1);
    printf("%d\n",ans[0] + ans[1]);
}
