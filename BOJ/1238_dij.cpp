#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);

    int u,v,w;
    vector<pair<int, int>>city[1001];
    vector<pair<int, int>>inv[1001];
    for(int i=0 ; i<m ; i++){
        scanf("%d%d%d",&u,&v,&w);
        city[u].push_back(make_pair(v,w));
        inv[v].push_back(make_pair(u,w));
    }
    vector<int> X(n+1,INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,x));
    X[x] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost > X[cur]) continue;
        for(int i=0 ; i<city[cur].size() ; i++){
            int next = city[cur][i].first;
            int nCost = city[cur][i].second;
            if(X[next]>nCost+cost){
                X[next] = nCost + cost;
                pq.push(make_pair(-X[next],next));
            }
        }
    }
    priority_queue<pair<int, int>> inv_pq;
    vector<int> invX(n+1,INF);
    inv_pq.push(make_pair(0,x));
    invX[x] = 0;
    while(!inv_pq.empty()){
        int cost = -inv_pq.top().first;
        int cur = inv_pq.top().second;
        inv_pq.pop();
        if(cost > invX[cur]) continue;
        for(int i=0 ; i<inv[cur].size() ; i++){
            int next = inv[cur][i].first;
            int nCost = inv[cur][i].second;
            if(invX[next]>nCost+cost){
                invX[next] = nCost + cost;
                inv_pq.push(make_pair(-invX[next],next));
            }
        }
    }
    int ans = -1;
    for(int i=1 ; i<=n ; i++){
        ans = max(ans, invX[i]+X[i]);
    }
    printf("%d\n",ans);
}
