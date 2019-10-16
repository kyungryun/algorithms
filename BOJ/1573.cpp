#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int main(){
    int V,E,start;
    scanf("%d%d",&V,&E);
    scanf("%d",&start);

    vector<pair<int, int>> g[20002];
    priority_queue<pair<int, int>> pq;
    int u,v,w;
    for(int i=0 ; i<E ; i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(make_pair(v,w));
    }
    pq.push(make_pair(0,start));
    int p[20002];
    memset(p, -1, sizeof(p));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(p[idx] != -1) continue;
        p[idx] = cost;
        for(int i=0 ; i<g[idx].size() ; i++){
            int next = g[idx][i].first;
            int nCost = -g[idx][i].second - cost;
            if(p[next] != -1) continue;
            pq.push(make_pair(nCost,next));
        }
    }
    for(int i=1 ; i<=V ; i++){
        if(p[i] == -1) printf("INF\n");
        else printf("%d\n",p[i]);
    }
}
