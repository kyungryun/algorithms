#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct GRAPH{
    int u;
    int v;
    GRAPH(int _u, int _v){
        u = _u;
        v = _v;
    }
};
vector<pair<string, string>> v;
vector<string> v2;
int f;
int group[200001];
int size[200001];
int find(int u){
    if(group[u] == u) return u;
    return group[u] = find(group[u]);
}
int merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        group[u] = v;
        size[v] += size[u];
        size[u] = 1;
    }
    return size[v];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&f);
        for(int i=0 ; i<2*f ; i++){
            group[i] = i;
            size[i] = 1;
        }
        for(int i=0 ; i<f ; i++){
            char f1[21],f2[21];
            scanf("%s %s",f1,f2);
            v.push_back(make_pair(f1,f2));
            v2.push_back(f1);
            v2.push_back(f2);
        }
        sort(v2.begin(),v2.end());
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
        for(int i=0 ; i<f ; i++){
            int uu = lower_bound(v2.begin(), v2.end(), v[i].first) - v2.begin();
            int vv = lower_bound(v2.begin(), v2.end(), v[i].second) - v2.begin();
            printf("%d\n",merge(uu,vv));
        }

        v.clear();
        v2.clear();
    }

}
