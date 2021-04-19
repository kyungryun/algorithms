#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n,m;
int map[9][9];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;
int ans;
void bfs(){
    int tMap[9][9];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            tMap[i][j] = map[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i=0 ; i<virus.size() ; i++) q.push(virus[i]);

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(tMap[nr][nc] != 0) continue;
            tMap[nr][nc] = 2;
            q.push(make_pair(nr,nc));
        }
    }
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(tMap[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
}
void dfs(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                dfs(cnt+1);
                map[i][j] = 0;
            }
        }
    }

}
int main(){
    scanf("%d%d",&n,&m);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2) virus.push_back(make_pair(i,j));
        }
    }
    dfs(0);

    printf("%d\n",ans);
}
