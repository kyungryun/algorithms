#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,d,c;
        scanf("%d%d%d",&n,&d,&c);
        int a,b,s;
        vector<pair<int, int>> com[10001];
        for(int i=0 ; i<d ; i++){
            scanf("%d%d%d",&a,&b,&s);
            com[b].push_back(make_pair(a,s));
        }
        vector<int> p(n+1, INF);
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0,c));
        p[c] = 0;
        while(!pq.empty()){
            int cost = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(p[cur] < cost) continue;

            for(int i=0 ; i<com[cur].size() ; i++){
                int next = com[cur][i].first;
                int nCost = com[cur][i].second;
                if(p[next] > nCost + cost){
                    p[next] = nCost + cost;
                    pq.push(make_pair(-p[next],next));
                }
            }
        }
        int cnt = 0;
        int time = 0;
        for(int i=1 ; i<=n ; i++){
            if(p[i] == INF) continue;
            cnt++;
            time = max(time,p[i]);
        }
        printf("%d %d\n",cnt, time);
    }
}
