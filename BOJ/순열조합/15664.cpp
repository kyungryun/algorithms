#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool visited[10];
int arr[10];
vector<int> v;
void dfs(int cnt, int idx){
    if(cnt == m){
        for(int i=0 ; i<v.size() ; i++) printf("%d ",v[i]);
        printf("\n");
        return;
    }
    bool used[10002] = {false,};
    for(int i = idx ; i<=n ; i++){
        if(!used[arr[i]] && !visited[i]){
            visited[i] = true;
            used[arr[i]] = true;
            v.push_back(arr[i]);
            dfs(cnt+1, i);
            v.pop_back();
            visited[i] = false;
        }

    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=n ; i++) scanf("%d",&arr[i]);
    sort(arr, arr+n+1);
    dfs(0, 1);
}
