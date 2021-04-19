#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int to[101][101][101];
bool visited[101][101][101];
int N,M,H;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int dh[2] = {1,-1};
int day;
int main(){
    scanf("%d%d%d",&M,&N,&H);

    queue<pair<pair<int,int>, pair<int,int>>> q;

    int toCnt = 0;
    for(int h=0 ; h<H ; h++){
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<M ; j++){
                scanf("%d",&to[h][i][j]);
                if(to[h][i][j] == 1){
                    q.push(make_pair(make_pair(h,0),make_pair(i,j)));
                }else if(to[h][i][j] == 0) toCnt++;
            }
        }
    }

    int change = 0;
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int h = q.front().first.first;
        int nDay = q.front().first.second;
        q.pop();

        if(visited[h][r][c]) continue;
        visited[h][r][c] = true;

        day = max(nDay, day);

        if(to[h][r][c] == 0) change++;
        to[h][r][c] = 1;

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >=M) continue;
            if(to[h][nr][nc] != 0) continue;
            q.push(make_pair(make_pair(h,nDay+1),make_pair(nr,nc)));
        }
        if(H > 1){
            for(int i=0 ; i<2 ; i++){
                int nh = h + dh[i];
                if(nh < 0 || nh >= H) continue;
                if(to[nh][r][c] != 0) continue;
                q.push(make_pair(make_pair(nh, nDay+1), make_pair(r,c)));
            }
        }

    }
    int ans = 0;
    if(change == toCnt) ans = day;
    else ans = -1;
    printf("%d\n",ans);

}
