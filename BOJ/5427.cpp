#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 987654321;
int t;
int w,h;
int sr,sc;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int map[1002][1002];
vector<pair<int, int>> fire;
int bfs(){
    bool visited[1002][1002];
    memset(visited,false, sizeof(visited));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    for(int i=0 ; i<fire.size() ; i++){
        q.push(make_pair(make_pair(0,0),make_pair(fire[i].first,fire[i].second)));
    }
    q.push(make_pair(make_pair(0,1),make_pair(sr,sc)));
    visited[sr][sc] = true;

    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int time = q.front().first.first;
        int s = q.front().first.second;
        q.pop();

        if(s && (r == 0 || r == h-1 || c == 0 || c == w-1)) return time+1;

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
            if(map[nr][nc] == 2 || map[nr][nc] == 1) continue;
            if(visited[nr][nc]) continue;

            if(s == 1) visited[nr][nc] = true;
            else map[nr][nc] = 2;

            q.push(make_pair(make_pair(time+1,s),make_pair(nr,nc)));
        }
    }
    return 0;
}

int main(){
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&w,&h);
        for(int i=0 ; i<h ; i++){
            for(int j=0 ; j<w ; j++){
                char c;
                scanf(" %c",&c);
                if(c == '#') map[i][j] = 1;
                else if(c == '@'){
                    sr = i;
                    sc = j;
                    map[i][j] = 0;
                }else if(c == '.') map[i][j] = 0;
                else{
                    map[i][j] = 2;
                    fire.push_back(make_pair(i,j));
                }
            }
        }
        int ans = bfs();
        if(ans) printf("%d\n",ans);
        else printf("IMPOSSIBLE\n");
        fire.clear();
        memset(map,0,sizeof(map));
    }
}
