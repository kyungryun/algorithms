#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int board[16][16];
int visited[16];
int dr[8] = {0,0,1,-1,-1,-1,1,1};
int dc[8] = {1,-1,0,0,-1,1,-1,1};
int ans;
bool check(int cnt){
    int i=1;
    bool flag = true;

    while(i < cnt && flag){
        if(visited[cnt] == visited[i] || abs(visited[cnt] - visited[i]) == cnt-i){
            flag = false;
        }
        i++;
    }
    return flag;
}
bool dfs(int cnt){
    if(check(cnt)){
        if(cnt == n) ans++;
        else{
            for(int i=1 ; i<=n ; i++){
                visited[cnt+1] = i;
                dfs(cnt+1);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(0);
    printf("%d\n",ans);
}
