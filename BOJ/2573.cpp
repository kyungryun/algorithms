#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int map[301][301];
bool visited[301][301];
int year = 1;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int cluster(){
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i=1 ; i<n-1 ; i++){
        for(int j=1 ; j<m-1 ; j++){
            if(map[i][j] != 0 && !visited[i][j]){
                cnt++;
                queue<pair<int, int>> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if(visited[r][c]) continue;
                    visited[r][c] = true;
                    for(int k=0 ; k<4 ; k++){
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc]) continue;
                        if(map[nr][nc] != 0) q.push(make_pair(nr,nc));
                    }
                }
            }
        }
    }
    return cnt;
}
void bfs(){
    while(1){
        vector<pair<int, pair<int, int>>> v;
        queue<pair<int, int>> q;
        for(int i=1 ; i<n-1 ; i++){
            for(int j=1 ; j<m-1 ; j++){
                if(map[i][j] != 0) q.push(make_pair(i,j));
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            int water = 0;
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(map[nr][nc] == 0) water++;
            }
            v.push_back(make_pair(water, make_pair(r,c)));
        }
        for(int i=0 ; i<v.size() ; i++){
            int r = v[i].second.first;
            int c = v[i].second.second;
            int w = v[i].first;
            map[r][c] = map[r][c]-w > 0 ? map[r][c]-w : 0;
        }
        int group = cluster();
        if(group >= 2) break;
        else if(group == 0){
            year = 0;
            break;
        }
        else year++;
    }

}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    bfs();
    printf("%d\n",year);
}
