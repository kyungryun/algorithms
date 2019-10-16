#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int INF = 987654321;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int ans[126][126];
int map[126][126];

void dijkstra(int n){
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push(make_pair(-map[0][0],make_pair(0,0)));
    ans[0][0] = map[0][0];
    while(!pq.empty()){
        int cost = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(ans[r][c] < cost) continue;

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if(ans[nr][nc] > cost + map[nr][nc]){
                ans[nr][nc] = cost + map[nr][nc];
                pq.push(make_pair(-ans[nr][nc],make_pair(nr,nc)));
            }
        }
    }
}
int main(){

    int t=1;
    while(1){
        int n;
        scanf("%d",&n);
        if(n == 0) break;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                scanf("%d",&map[i][j]);
                ans[i][j] = INF;
            }
        }
        dijkstra(n);

        printf("Problem %d: %d\n",t++, ans[n-1][n-1]);
    }
}
