#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
int m[30][30];
int visit[30][30];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans[25*25];
int n;
void bfs(int x, int y, int cnt){
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));

    visit[x][y] = cnt;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx >= 0 && xx< n && yy>= 0 && yy<n ){
                if(m[xx][yy] == 1 && visit[xx][yy] == 0){
                    q.push(make_pair(xx,yy));
                    visit[xx][yy] = cnt;
                }
            }
        }
    }
}
int main(){

    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%1d",&m[i][j]);
        }
    }
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(m[i][j] == 1 && visit[i][j] == 0){
                bfs(i,j, ++cnt);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            ans[visit[i][j]]++;
        }
    }
    printf("%d\n",cnt);
    sort(ans+1, ans+cnt+1);
    for(int i=1 ; i<=cnt ; i++){
        printf("%d\n",ans[i]);
    }
}
