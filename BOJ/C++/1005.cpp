#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int in[1001];
int time[1001];
int build[1001];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,from,to,w;
        
        vector<int> v[1001];
        scanf("%d%d",&n,&k);
        for(int i=0 ; i<1001 ; i++){
            in[i] = time[i] = build[i] = 0;
        }
        for(int i=1 ; i<=n ; i++){
            scanf("%d",&time[i]);
        }
        for(int i=1 ; i<=k ; i++){
            scanf("%d%d",&from,&to);
            v[from].push_back(to);
            in[to]++;
        }
        scanf("%d",&w);
        
        queue<int> q;
        for(int i=1 ; i<=n ; i++){
            if(in[i] == 0) q.push(i);
            build[i] += time[i];
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0 ; i<v[cur].size() ; i++){
                int next = v[cur][i];
                build[next] = max(build[next], build[cur] + time[next]);
                in[next]--;
                if(in[next] == 0) q.push(next);
            }
        }
        printf("%d\n",build[w]);
    }
}