#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,k;
bool visited[100001]={false,};
int main(){
    scanf("%d%d",&n,&k);
    queue<pair<int, int>> q;
    q.push(make_pair(n,0));
    visited[n] = true;

    while(!q.empty()){
        int now = q.front().first;
        int t = q.front().second;
        q.pop();
        if(now == k){
            printf("%d\n",t);
            return 0;
        }

        if(now+1 <= 100000 && !visited[now+1]){
            visited[now+1] = true;
            q.push(make_pair(now+1, t+1));
        }
        if(now-1 >= 0 && !visited[now-1] ){
            visited[now-1] = true;
            q.push(make_pair(now-1, t+1));
        }
        if(now*2 <= 100000 && !visited[now*2]){
            visited[now*2] = true;
            q.push(make_pair(now*2, t+1));
        }
    }
}
