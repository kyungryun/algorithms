#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int map[101][101];
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int dist[101][101];
int bfs(){
    dist[0][0] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int dx = x + di[i];
            int dy = y + dj[i];

            if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if(dist[dx][dy] > dist[x][y] + map[dx][dy]){
                dist[dx][dy] = dist[x][y] + map[dx][dy];
                q.push(make_pair(dx,dy));
            }
        }
    }
    return dist[n-1][n-1];
}
int main(){
    int T;
    scanf("%d",&T);

    for(int t=1 ; t<=T ; t++){

        scanf("%d",&n);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                scanf("%1d",&map[i][j]);
                dist[i][j] = 987654321;
            }
        }
        printf("#%d %d\n",t,bfs());
    }
}
