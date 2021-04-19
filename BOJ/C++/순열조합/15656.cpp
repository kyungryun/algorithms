#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool visited[9];
vector<int> v;
int arr[9];
void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=0 ; i<v.size() ; i++) printf("%d ",arr[v[i]]);
        printf("\n");
        return;
    }
    for(int i = 1 ; i<=n ; i++){
        v.push_back(i);
        dfs(i, cnt+1);
        v.pop_back();
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=n ; i++) scanf("%d",&arr[i]);
    sort(arr, arr+n+1);
    dfs(1,0);
}
