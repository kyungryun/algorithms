#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int t,l;
int map[301][301];
bool visited[301][301];
int sr,sc,er,ec;
int dr[8] = {-2,-2,-1,1,2,2,1,-1};
int dc[8] = {-1,1,2,2,1,-1,-2,-2};
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&l);
        scanf("%d%d%d%d",&sr,&sc,&er,&ec);
        for(int i=0 ; i<301 ; i++){
            for(int j=0 ; j<301 ; j++){
                map[i][j] = 0, visited[i][j] = 0;
            }
        }
        queue<pair<int, int>> q;
        q.push(make_pair(sr,sc));
        visited[sr][sc] = true;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r == er && c == ec){
                break;
            }
            for(int i=0 ; i<8 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= l || nc >= l || visited[nr][nc]) continue;
                map[nr][nc] = map[r][c] + 1;
                visited[nr][nc] = true;
                q.push(make_pair(nr,nc));
            }
        }
        printf("%d\n",map[er][ec]);
    }
}
