#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
int dur[9];
int w[9];
int n;
int ans = 0;

void dfs(int cnt){
    if(cnt >= n){
        int t = 0;
        for(int i=0 ; i<n ; i++){
            if(dur[i] <= 0) t++;
        }
        ans = max(ans, t);
        return;
    }


    if(dur[cnt] <= 0) dfs(cnt+1);
    else{
        bool check = false;
        for(int i=0 ; i<n ; i++){
            if(dur[i] <= 0 || i == cnt) continue;

            dur[i] -= w[cnt];
            dur[cnt] -= w[i];
            check = true;
            dfs(cnt+1);
            dur[i] += w[cnt];
            dur[cnt] += w[i];
        }
        if(!check) dfs(n);
    }

}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d%d",&dur[i],&w[i]);
    }
    dfs(0);
    printf("%d\n",ans);
}
