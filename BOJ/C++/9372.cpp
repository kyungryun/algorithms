#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

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
int n,m;

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
int uf(){
    sort(edge.begin(), edge.end(), comp);
    int ans = 0;
    for(int i=0 ; i<edge.size() ; i++){
        if(merge(edge[i].u, edge[i].v)){
            ans++;
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&n,&m);
        for(int i=1 ; i<=n ; i++) group[i] = i;
        for(int i=0 ; i<m ; i++){
            scanf("%d%d",&a,&b);
            edge.push_back(NODE(a,b,1));
            edge.push_back(NODE(b,a,1));
        }
        printf("%d\n",uf());
        memset(group, 0, sizeof(group));
        edge.clear();
    }

}
