#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int in[32001];

int main(){
    int n1,n2;
    scanf("%d%d",&n,&m);
    vector<vector<int>> v(n+1);
    for(int i=0 ; i<m ; i++){
        scanf("%d%d",&n1,&n2);
        v[n1].push_back(n2);
        in[n2]++;
    }

    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d ",now);
        for(int i=0 ; i< v[now].size() ; i++){
            int next = v[now][i];
            in[next]--;
            if(in[next] == 0) q.push(next);
        }
    }
    printf("\n");
}