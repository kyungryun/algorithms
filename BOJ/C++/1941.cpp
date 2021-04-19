#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;

int arr[5][5];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
vector<int> v;
int ans;
bool visited[25];
bool sCnt(){
    int cnt = 0;
    for(int i=0 ; i<25 ; i++){
        if(visited[i]){
            if(arr[i/5][i%5] == 1) cnt++;
        }
    }
    if(cnt >= 4) return 1;
    else return 0;
}
bool connect(){
    bool temp[5][5]={false,};
    bool visit[5][5]={false,};
    bool flag = true;
    queue<pair<int, int>> q;
    for(int i=0 ; i<25 ; i++){
        if(visited[i]){
            int r = i/5;
            int c = i%5;
            temp[r][c] = true;
            if(flag){
                q.push(make_pair(r,c));
                flag = false;
                visit[r][c] = true;
            }
        }
    }
    int cnt = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(cnt == 7) return 1;

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
            if(temp[nr][nc] && !visit[nr][nc]){
                visit[nr][nc] = true;
                q.push(make_pair(nr,nc));
                cnt++;
            }
        }
    }
    return 0;
}
void dfs(int cnt, int idx){
    if(cnt == 7){
        if(sCnt()){
            ans += connect();
        }
        return;
    }
    for(int i=idx ; i<25 ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(cnt+1, i);
        visited[i] = false;
    }
}
int main(){
    char c;
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
            scanf(" %c",&c);
            if(c == 'Y') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    dfs(0,0);
    printf("%d\n",ans);
}
