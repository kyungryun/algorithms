#include <cstdio>
#include <queue>
using namespace std;

const int INF = 987654321;
int n,m,k;
int block[1001][1001];
int d[1001][1001][11];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%1d",&block[i][j]);
        }
    }
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0,make_pair(0,0)));
    d[0][0][0] = 1;
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int b = q.front().first;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc<0 || nr >=n || nc >=m) continue;
            if(block[nr][nc] == 0 && d[nr][nc][b] == 0){
                d[nr][nc][b] = d[r][c][b]+1;
                q.push(make_pair(b,make_pair(nr,nc)));
            }
            if(b+1<= k && block[nr][nc] == 1 && d[nr][nc][b+1] == 0){
                d[nr][nc][b+1] = d[r][c][b] + 1;
                q.push(make_pair(b+1,make_pair(nr,nc)));
            }
        }
    }
    int ans = INF;
    for(int i=0 ; i<=k ; i++){
        if(d[n-1][m-1][i] == 0) continue;
        ans = min(ans, d[n-1][m-1][i]);
    }
    printf("%d\n",ans==INF ? -1 : ans);
}
