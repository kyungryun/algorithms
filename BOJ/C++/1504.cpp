#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 800001;
vector<pair<int, int>> g[801];
vector<int> dijkstra(int start, int v){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,start));
    vector<int>p(v+1, INF);
    p[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(p[cur] < cost) continue;
        for(int i=0 ; i<g[cur].size() ; i++){
            int next = g[cur][i].first;
            int nCost = g[cur][i].second;
            if(p[next] > nCost + cost){
                p[next] = nCost + cost;
                pq.push(make_pair(-p[next],next));
            }
        }
    }
    return p;
}
int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    int u,v,w;
    for(int i=0 ; i<e ; i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    int e1,e2;
    scanf("%d%d",&e1,&e2);
    int ans1 = 0;
    int ans2 = 0;
    vector<int> d;
    d = dijkstra(1, n);
    ans1 = d[e1];
    ans2 = d[e2];
    d = dijkstra(e1,n);
    ans1 += d[e2];
    ans2 += d[n];
    d = dijkstra(e2,n);
    ans1 += d[n];
    ans2 += d[e1];

    ans1 = min(ans1,ans2);
    if(ans1 > INF) printf("-1\n");
    else printf("%d\n",ans1);
}
