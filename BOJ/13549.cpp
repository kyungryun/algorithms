#include <cstdio>
#include <stack>
#include <algorithm>
#include <deque>
using namespace std;
int n,k;
int ans = 987654321;
bool visited[100001];
int main(){
    scanf("%d%d",&n,&k);

    deque<pair<int,int>> q;
    q.push_back(make_pair(n,0));

    while(!q.empty()){
        int now = q.front().first;
        int t = q.front().second;
        q.pop_front();
        if(now == k){
            ans = min(ans, t);
        }
        if(now*2 <= 100001 && !visited[now*2]){
            visited[now*2] = true;
            q.push_front(make_pair(now*2, t));
        }
        if(now-1 >= 0 && !visited[now-1]){
            visited[now-1] = true;
            q.push_back(make_pair(now-1, t+1));
        }
        if(now+1 <= 100001 && !visited[now+1]){
            visited[now+1] = true;
            q.push_back(make_pair(now+1, t+1));
        }

    }
    printf("%d\n",ans);
}
