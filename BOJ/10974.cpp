#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n;
bool visited[8]={false,};
vector<int> v;
int arr[8];
void dfs(int cnt){
    if(cnt == n){
        for(int i=0 ; i<v.size() ; i++){
            printf("%d ",arr[v[i]]);
        }
        printf("\n");
        return;
    }
    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            dfs(cnt+1);
            visited[i] = false;
            v.pop_back();
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        arr[i] = i+1;
    }
    dfs(0);
}
