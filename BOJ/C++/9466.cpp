#include <cstdio>

using namespace std;
int student[100001];
bool visit[100001];
bool finish[100001];
int cnt,t,n;
void dfs(int idx){
    visit[idx] = true;
    int next = student[idx];
    if(!visit[next]){
        dfs(next);
    }else{
        if(!finish[next]){
            for(int i=next ; i != idx; i = student[i]){
                cnt++;
            }
            cnt++;
        }
    }

    finish[idx] = true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1 ; i<=n ; i++){
            student[i] = 0;
            finish[i] = visit[i] = false;
        }
        for(int i=1 ; i<=n ; i++){
            scanf("%d",&student[i]);
        }

        cnt = 0;
        for(int i=1 ; i<=n ; i++){
            if(!visit[i]) dfs(i);
        }
        printf("%d\n",n-cnt);
    }
}
