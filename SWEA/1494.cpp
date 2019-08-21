#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long ans;
long long INF = 987987654321;
int n;
struct Point{
    int x;
    int y;
}point[20];
bool visited[20];

void calc(){
    long long x = 0;
    long long y = 0;
    for(int i=0 ; i<n ; i++){
        if(visited[i]) {
            x += point[i].x;
            y += point[i].y;
        }
        else{
            x -= point[i].x;
            y -= point[i].y;
        }
    }

    if(ans > x*x + y*y) ans = x*x + y*y;
}
void dfs(int cnt, int idx){
    if(cnt == n/2){
        calc();
        return;
    }
    for(int i=idx ; i<n ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(cnt+1, i+1);
        visited[i] = false;
    }
}
int main(){
    int T;
    scanf("%d",&T);

    for(int t=1 ; t<=T ; t++){
        memset(visited, false, sizeof(visited));
        memset(point, 0, sizeof(point));
        ans = INF;

        scanf("%d",&n);
        for(int i=0 ; i<n ; i++){
            int x,y;
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        dfs(0, 0);
        printf("#%d %lld\n",t,ans);
    }
}
