#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


const int INF = 987654321;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int n,m;
int lab[51][51];
int temp[51][51];
bool checked[51][51];
bool visited[11];
vector<pair<int, int>> virus;
int ans;

int spread(queue<pair<int, pair<int, int>>> &q){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            temp[i][j] = lab[i][j];
        }
    }
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int t = q.front().first;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r+ dr[i];
            int nc = c+ dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= n || checked[nr][nc]) continue;
            if(temp[nr][nc] == 0){
                checked[nr][nc] = true;
                temp[nr][nc] = t+1;
                q.push(make_pair(t+1,make_pair(nr,nc)));
            }
        }
    }
    int time = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(temp[i][j] == 0 && !checked[i][j]) return -1;
            if(checked[i][j]) time = max(time, temp[i][j]);
        }
    }
    return time;
}
void dfs(int idx, int cnt){
    if(cnt == m){
        memset(checked, false,sizeof(checked));
        queue<pair<int, pair<int, int>>> q;
        for(int i=0 ; i<virus.size() ; i++){
            if(visited[i]){
                checked[virus[i].first][virus[i].second] = true;
                q.push(make_pair(0, make_pair(virus[i].first,virus[i].second)));
            }
        }
        int time = spread(q);
        if(time != -1) ans = min(ans, time);
        return;
    }
    for(int i=idx ; i<virus.size() ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i,cnt+1);
        visited[i] = false;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&lab[i][j]);
            if(lab[i][j] == 2){
                lab[i][j] = 0;
                virus.push_back(make_pair(i,j));
            }
        }
    }
    ans = INF;
    dfs(0,0);
    printf("%d\n",ans == INF ? -1 : ans);
}
