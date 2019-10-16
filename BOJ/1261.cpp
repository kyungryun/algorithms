#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int main(){
    int n,m;
    int arr[101][101];
    int dist[101][101];
    bool visited[10001];
    scanf("%d%d",&m,&n);
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            scanf("%1d",&arr[i][j]);
            dist[i][j] = INF;
        }
    }
    dist[1][1] = 0;
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push(make_pair(0,make_pair(1,1)));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(dist[r][c] < cost) continue;
        for(int i=0 ; i<4;  i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nc < 1 || nr >n || nc > m) continue;
            if(dist[nr][nc] > cost+arr[nr][nc]){
                dist[nr][nc] = cost+arr[nr][nc];
                pq.push(make_pair(-dist[nr][nc],make_pair(nr,nc)));
            }
        }
    }
    printf("%d\n",dist[n][m]);
}
