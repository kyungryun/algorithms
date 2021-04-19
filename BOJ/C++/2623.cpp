#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n,m,k;
int indeg[1001];
vector<int> v[1001];
vector<int> ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<m ; i++){
        int cur, next;
        scanf("%d",&k);
        scanf("%d",&cur);
        for(int j=0 ; j<k-1 ; j++){
            scanf("%d",&next);
            v[cur].push_back(next);
            indeg[next]++;
            cur = next;
        }
    }
    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(indeg[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0 ; i<v[cur].size() ; i++){
            int next = v[cur][i];
            indeg[next]--;
            if(indeg[next] == 0){
                q.push(next);
                ans.push_back(next);
            }
        }
    }

    if(ans.size() == n){
        for(int i=0 ; i<ans.size() ; i++) printf("%d\n",ans[i]);
    }else printf("0\n");
}