#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int dr[8] = {0,1,1,1,0,-1,-1,-1};
int dc[8] = {-1,-1,0,1,1,1,0,-1};
int n;
char map[301][301];
bool visited[301][301];
int ans;
queue<pair<int ,int>> q;
int check(int r, int c){
    int mine = 0;
    for(int i=0 ; i<8 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(map[nr][nc] == '*') mine++;
    }
    return mine;
}
void pushQ(int r, int c){
    for(int i=0 ; i<8 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(map[nr][nc] == '.') q.push(make_pair(nr,nc));
    }
}
void bfs(){
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(visited[r][c]) continue;
        map[r][c] = check(r,c) + '0';
        if(map[r][c] == '0'){
            visited[r][c] = true;
            pushQ(r,c);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        scanf("%d",&n);
        ans = 0;
        memset(visited,false,sizeof(visited));
        for(int i=0 ; i<n ; i++) scanf("%s",map[i]);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(map[i][j] == '.'){
                    if(check(i,j) == 0){
                        map[i][j] = '0';
                        visited[i][j] = true;
                        pushQ(i,j);
                        bfs();
                        ans++;
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(map[i][j] == '.') ans++;
            }
        }
        printf("#%d %d\n",t, ans);
    }
}
