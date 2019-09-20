#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
vector<pair<int, int>> v[1001];
bool visited[1001];
struct NODE{
    int u;
    int v;
    int w;
    NODE(int _u, int _v, int _w){
        u = _u, v = _v, w = _w;
    }
};
int group[1001];
vector<NODE> edge;
int find(int u){
    if(u == group[u]) return u;
    return group[u] = find(group[u]);
}
int merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    group[v] = u;
    return 1;
}
bool comp(NODE a, NODE b){
    return a.w < b.w;
}
int ks(){
    sort(edge.begin(), edge.end(), comp);
    int ans = 0;
    for(int i=0 ; i<edge.size() ; i++){
        if(merge(edge[i].u, edge[i].v)){
            ans += edge[i].w;
        }
    }
    return ans;
}
void pq(int s){
    visited[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i=0 ; i<v[s].size() ; i++){
        int next = v[s][i].first;
        int cost = v[s][i].second;
        pq.push(make_pair(cost, next));
    }
    int ans = 0;
    while(!pq.empty()){
        int vertex = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(visited[vertex]) continue;
        visited[vertex] = true;
        ans += weight;

        for(int i=0 ; i<v[vertex].size() ; i++){
            int next = v[vertex][i].first;
            int cost = v[vertex][i].second;
            pq.push(make_pair(cost, next));
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=n ; i++) group[i] = i;
    for(int i=0 ; i<m ; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge.push_back(NODE(a,b,c));
        edge.push_back(NODE(b,a,c));

        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    printf("%d\n",ks());
    //pq(1);
}
