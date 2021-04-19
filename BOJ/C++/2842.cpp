
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char map[55][55];
int h[55][55];
vector<int> v;
int ans = 1000000;
int sr,sc;
int dr[8] = {0,1,1,1,0,-1,-1,-1};
int dc[8] = {-1,-1,0,1,1,1,0,-1};
bool visited[55][55];
int home;
int dfs(int r, int c, int MIN, int MAX){
    int res = 0;

    if(h[r][c] < MIN || h[r][c] > MAX) return 0;
    if(map[r][c] == 'K') res++;

    for(int i=0 ; i<8 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < n){
            if(!visited[nr][nc]){
                visited[nr][nc] = true;
                res += dfs(nr,nc,MIN,MAX);
            }
        }
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%s",map[i]);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(map[i][j] == 'P'){
                sr = i;
                sc = j;
            }
            if(map[i][j] == 'K') home++;
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&h[i][j]);
            v.push_back(h[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int j = 0;
    for(int i=0 ; i<v.size() ; i++){
        while(1){
            memset(visited,false,sizeof(visited));
            if(dfs(sr,sc,v[j],v[i]) != home){
                break;
            }
            ans = min(ans, v[i] - v[j]);
            j++;
        }
    }
    printf("%d\n",ans);
}
