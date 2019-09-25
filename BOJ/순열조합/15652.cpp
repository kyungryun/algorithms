#include <cstdio>
#include <vector>
using namespace std;

int n,m;
bool visited[9];
vector<int> v;
void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=0 ; i<v.size() ; i++) printf("%d ",v[i]);
        printf("\n");
        return;
    }
    for(int i = idx ; i<=n ; i++){
        v.push_back(i);
        dfs(i, cnt+1);
        v.pop_back();
    }
}
int main(){
    scanf("%d%d",&n,&m);
    dfs(1,0);
}
