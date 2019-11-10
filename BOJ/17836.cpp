#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[101][101];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int n,m,t;
bool p;
int v[101][101];
int v2[101][101];
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    queue<pair<pair<int, int>, pair<int, bool>>> q;
    q.push(make_pair(make_pair(0,0),make_pair(0,false)));
    v[0][0] = true;
    int ans = 0;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second.first;
        bool sword = q.front().second.second;
        q.pop();
        if(map[r][c] == 2) sword = true;
        if(r == n-1 && c == m-1){
            if(time <= t){
                p = true;
                ans = time;
            }
            break;
        }
        for(int k=0 ; k<4 ; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr < 0 || nr >= n || nc < 0 || nc >=m) continue;
            if(sword){
                if(v2[nr][nc]) continue;
                v2[nr][nc] = true;
            }else{
                if(v[nr][nc] || map[nr][nc] == 1) continue;
                v[nr][nc] = true;
            }
            q.push(make_pair(make_pair(nr,nc),make_pair(time+1,sword)));
        }
    }
    if(p) printf("%d\n",ans);
    else printf("Fail\n");
}
