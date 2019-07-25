#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct Edge{
    long long x;
    long long y;
};
int root[1001];
int find(int x){
    if(root[x] == x ) return x;
    else return root[x] = find(root[x]);
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) root[y] = x;
}
bool isCycle(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}
int main(){
    int t;
    scanf("%d",&t);

    for(int T=1 ; T<=t ; T++){
        long long ans = 0;
        int n;
        double e;
        Edge edge[1001];
        vector<pair<long long, pair<long long, long long> >> v;
        scanf("%d",&n);

        for(int i=0 ; i<n ; i++) scanf("%lld",&edge[i].x);
        for(int i=0 ; i<n ; i++) scanf("%lld",&edge[i].y);
        for(int i=0 ; i<n ; i++) root[i] = i;
        scanf("%lf",&e);

        for(int i=0 ; i<n-1 ; i++){
            for(int j=i+1 ; j<n ; j++){
                long long d = (edge[i].x - edge[j].x) * (edge[i].x - edge[j].x) +
                              (edge[i].y - edge[j].y) * (edge[i].y - edge[j].y);
                v.push_back(make_pair(d,make_pair(i,j)));
            }
        }
        sort(v.begin(), v.end());
        int size = v.size();
        for(int i=0 ; i<size ; i++){
            if(!isCycle(v[i].second.first, v[i].second.second)){
                Union(v[i].second.first, v[i].second.second);
                ans += v[i].first;
            }
        }
        printf("#%d %.lf\n",T,(double)ans*e);
    }
}
