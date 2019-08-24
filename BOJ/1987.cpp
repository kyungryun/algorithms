#include <cstdio>
#include <algorithm>

using namespace std;

int R,C;
char map[22][22];
bool visited[22][22];
int alph[28];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int ans = 1;
void dfs(int r, int c, int cnt){
    if(alph[map[r][c]-'A'] > 1){
        ans = max(ans, cnt);
        return;
    }
    for(int i=0 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >=R || nc < 0 || nc >= C || visited[nr][nc]) continue;
        visited[nr][nc] = true;
        alph[map[nr][nc]-'A']++;
        dfs(nr, nc, cnt+1);
        alph[map[nr][nc]-'A']--;
        visited[nr][nc] = false;
    }
    ans = max(ans, cnt+1);
}
int main(){
    scanf("%d%d",&R,&C);
    for(int i=0 ; i<R; i++){
        scanf("%s",map[i]);
    }
    alph[map[0][0]-'A'] = 1;
    visited[0][0] = true;
    dfs(0, 0, 0);
    printf("%d\n",ans);
}
