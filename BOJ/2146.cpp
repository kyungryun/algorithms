#include <cstdio>
#include <queue>
using namespace std;

int n;
int map[101][101];
int cluster[101][101];
int bridge[101][101];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void dfs(int r, int c, int idx){
    cluster[r][c] = idx;
    map[r][c] = 0;
    for(int i=0 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nc >= 0 && nr < n && nc < n && map[nr][nc] != 0){

            dfs(nr,nc,idx);
        }
    }
}
void bfs(){
    queue<pair<int, int>> q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(cluster[i][j] != 0) q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr < n && nc >=0 && nc < n){
                if(cluster[nr][nc] == 0 && bridge[nr][nc] == 0){
                    bridge[nr][nc] = bridge[r][c] + 1;
                    cluster[nr][nc] = cluster[r][c];
                    q.push(make_pair(nr,nc));
                }
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
    int index = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(map[i][j] != 0){
                dfs(i,j,index);
                index++;
            }
        }
    }
    bfs();
    int ans = 987654321;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<4 ; k++){
                int r = i + dr[k];
                int c = j + dc[k];
                if(r >= 0 && r < n && c >= 0 && c < n){
                    if(cluster[r][c] != cluster[i][j]){
                        ans = min(ans,bridge[i][j] + bridge[r][c]);
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}
