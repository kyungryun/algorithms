#include <cstdio>
#include <vector>
using namespace std;

int n,m;
bool visited[9];
vector<int> v;
void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=1 ; i<=n ; i++){
            if(visited[i]) printf("%d ",i);
        }
        printf("\n");
        return;
    }
    for(int i = idx ; i<=n ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, cnt+1);
        visited[i] = false;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    dfs(1,0);
}
