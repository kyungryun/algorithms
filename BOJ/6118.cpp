#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    vector<pair<int, int>> h[20002];
    for(int i=0 ; i<m ; i++){
        scanf("%d%d",&a,&b);
        h[a].push_back(make_pair(b,1));
        h[b].push_back(make_pair(a,1));
    }

    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0,1));
    vector<int>p(n+1,INF);
    p[1] = 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(p[cur] < cost) continue;

        for(int i=0 ; i<h[cur].size() ; i++){
            int next = h[cur][i].first;
            int nCost = h[cur][i].second;
            if(p[next] > cost + nCost){
                p[next] = cost + nCost;
                pq.push(make_pair(-p[next],next));
            }
        }
    }
    vector<pair<int, int>> ans;
    for(int i=1 ; i<=n ; i++){
        if(p[i] == INF) continue;
        ans.push_back(make_pair(p[i],i));
    }
    sort(ans.begin(),ans.end(), comp);
    int cnt = 0;
    for(int i=0 ; i<ans.size() ; i++){
        if(ans[0].first == ans[i].first) cnt++;
    }
    printf("%d %d %d\n",ans[0].second, ans[0].first, cnt);
}
