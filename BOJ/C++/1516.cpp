#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[501];
int indeg[501];
int time[501];
int build[501];
int n,m,seq;
int main(){
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++){
        scanf("%d",&time[i]);
        while(1){
            scanf("%d",&seq);
            if(seq != -1){
                v[seq].push_back(i);
                indeg[i]++;
            }
            else break;
        }
    }
    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(indeg[i] == 0) q.push(i);
        build[i] += time[i];
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0 ; i<v[cur].size() ; i++){
            int next = v[cur][i];
            build[next] = max(build[next], build[cur] + time[next]);
            indeg[next]--;
            if(indeg[next] == 0) q.push(next);
        }
    }
    for(int i=1 ; i<=n ; i++) printf("%d\n",build[i]);
}