#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int indeg[32001];
vector<int> v[32001];
int n,m,a,b;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<m ; i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int, vector<int>> pq;
    for(int i=1 ; i<=n ; i++){
        if(indeg[i] == 0) pq.push(-i);
    }
    while(!pq.empty()){
        int cur = -pq.top();
        pq.pop();
        printf("%d ", cur);
        for(int i=0 ; i< v[cur].size() ; i++){
            int next = v[cur][i];
            indeg[next]--;
            if(indeg[next] == 0) pq.push(-next);
        }
    }
    printf("\n");
}