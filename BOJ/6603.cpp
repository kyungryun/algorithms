#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int arr[14];
bool visited[14];
vector<int> v;
void dfs(int idx, int cnt, int k){
    if(cnt == 6){
        for(int i=0 ; i<v.size() ; i++) printf("%d ",v[i]);
        printf("\n");
        return;
    }
    for(int i = idx ; i<k ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        dfs(i,cnt+1,k);
        v.pop_back();
        visited[i] = false;
    }
}
int main(){
    while(1){
        int k;
        scanf("%d",&k);
        if(k == 0) break;
        for(int i=0 ; i<k ; i++){
            scanf("%d",&arr[i]);
        }
        dfs(0,0,k);
        printf("\n");
        v.clear();
        memset(visited,false,sizeof(visited));
    }
}
