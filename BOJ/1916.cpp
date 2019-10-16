#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 1000;
int main(){
    int n,m,s,e;
    scanf("%d%d",&n,&m);

    int u,v,w;
    vector<pair<int, int>> bus[1002];
    for(int i=0 ; i<m ; i++){
        scanf("%d%d%d",&u,&v,&w);
        bus[u].push_back(make_pair(v,w));
    }
    scanf("%d%d",&s,&e);

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,s));
    vector<int> p(n+1,INF);
    p[s] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost <= p[cur]){
            for(int i=0 ; i<bus[cur].size() ; i++){
                int next = bus[cur][i].first;
                int nCost = bus[cur][i].second;
                if(p[next] > nCost + cost){
                    p[next] = nCost + cost;
                    pq.push(make_pair(-p[next],next));
                }
            }
        }
    }
    printf("%d\n",p[e]);
}
