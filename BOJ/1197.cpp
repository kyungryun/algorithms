#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int V,E;
struct G{
    int a;
    int b;
    int c;
    G(int _a, int _b, int _c){
        a = _a;
        b = _b;
        c = _c;
    }
};
vector<G> v;
int group[100001];
int find(int x){
    if(group[x] == x) return x;
    return group[x] = find(group[x]);
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    group[y]  = x;
}
bool compare(G a, G b){
    return a.c < b.c;
}
int mst(){
    int ans = 0;
    sort(v.begin(),v.end(), compare);
    for(int i=0 ; i<v.size() ; i++){
        if(find(v[i].a) == find(v[i].b)) continue;
        merge(v[i].a , v[i].b);
        ans += v[i].c;
    }
    return ans;
}
int main(){
    scanf("%d%d",&V,&E);
    for(int i=0 ; i<E;  i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back(G(a,b,c));
        v.push_back(G(b,a,c));
    }
    for(int i=1 ; i<=V ; i++) group[i] = i;
    printf("%d\n",mst());
}
