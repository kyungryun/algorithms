#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int map[11][11];
int cluster[11][11];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int cnt;
int ans = -1;
struct EDGE{
    int u;
    int v;
    int w;
    EDGE(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};
bool comp(EDGE a, EDGE b){
    return a.w < b.w;
}
vector<EDGE> graph;
int group[7];

int find(int u){
    if(u == group[u]) return u;
    return group[u] = find(group[u]);
}
int merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    group[v] = u;
    return 1;
}
bool comp2(EDGE a, EDGE b){
    return a.u == b.u && a.v == b.v && a.w == b.w;
}
void mst(){
    if(graph.size() == 0) return;

    graph.erase(unique(graph.begin(),graph.end(), comp2),graph.end());
    sort(graph.begin(), graph.end(), comp);
    int cost = 0;
    for(int i=0 ; i<graph.size() ; i++){
        if(merge(graph[i].u,graph[i].v)){
            cost += graph[i].w;
        }
    }
    bool flag = true;
    int root = group[1];
    for(int i=2 ; i<=cnt ; i++){
        if(root != find(group[i])){
            flag = false;
            break;
        }
    }
    if(flag) ans = cost;
}
void dfs(int cnt, int r, int c){
    cluster[r][c] = cnt;
    for(int i=0 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
        if(map[nr][nc] == 1){
            map[nr][nc] = 0;
            cluster[nr][nc] = cnt;
            dfs(cnt, nr,nc);
        }
    }
}
void bfs(int s){
    queue<pair<int, int>> q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(cluster[i][j] == s) q.push(make_pair(i,j));
        }
    }
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            int bridge = 0;
            while(1){
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && cluster[nr][nc] != s){
                    if(cluster[nr][nc] == 0) bridge++;

                    if(cluster[nr][nc] != 0){
                        if(bridge > 1){
                            graph.push_back(EDGE(s, cluster[nr][nc], bridge));
                            graph.push_back(EDGE(cluster[nr][nc], s, bridge));
                        }
                        break;
                    }
                    nr += dr[i];
                    nc += dc[i];
                }else{
                    break;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    cnt = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(map[i][j] == 1){
                dfs(cnt+1, i, j);
                cnt++;
            }
        }
    }
    for(int i=1 ; i<=cnt ; i++) bfs(i);
    for(int i=1 ; i<=cnt ; i++) group[i] = i;
    mst();
    printf("%d\n",ans);
}
