#include <cstdio>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,k;
int ans;
int visited[100001];

int main(){
    scanf("%d%d",&n,&k);

    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    memset(visited, -1, sizeof(visited));
    while(!q.empty()){
        int now = q.front().first;
        int t = q.front().second;
        q.pop();
        if(now == k){
            ans = t;
            break;
        }
        if(now-1 >= 0 && visited[now-1] == -1){
            visited[now-1] = now;
            q.push(make_pair(now-1, t+1));
        }
        if(now+1 <= 100001 && visited[now+1] == -1){
            visited[now+1] = now;
            q.push(make_pair(now+1, t+1));
        }
        if(now*2 <= 100001 && visited[now*2] == -1){
            visited[now*2] = now;
            q.push(make_pair(now*2, t+1));
        }
    }
    stack<int> path;
    int pos = k;
    while(pos != n){
        path.push(visited[pos]);
        pos = visited[pos];
    }
    printf("%d\n",ans);
    while(!path.empty()){
        printf("%d ",path.top());
        path.pop();
    }
    printf("%d\n",k);
}
