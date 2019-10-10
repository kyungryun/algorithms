#include <cstdio>
#include <vector>

const int INF = 987654321;
int n,m;
int g[101][101] = {0,};
bool cycle[101];
int ans = 0;
void dfs(int now){
    if(cycle[now]) return;
    cycle[now] = true;
    for(int i=0 ; i<n ; i++){
        if(g[now][i] != INF && !cycle[i]){
            dfs(i);
            ans++;
        }
    }
}
int main(){

    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            g[i][j] = INF;
        }
    }
    for(int i=0 ; i<m ; i++){
        int from,to;
        scanf("%d%d",&from,&to);
        g[from-1][to-1] = 1;
        g[to-1][from-1] = 1;
    }

    dfs(0);

    printf("%d\n",ans);
}
