#include <cstdio>
#include <algorithm>

using namespace std;

int n,s;
int arr[21];
int ans;
void dfs(int cnt, int sum){
    if(cnt >= n) return;
    sum += arr[cnt];
    if(sum == s) ans++;
    dfs(cnt+1, sum - arr[cnt]);
    dfs(cnt+1, sum);
}
int main(){
    scanf("%d%d",&n,&s);
    for(int i=0 ; i<n ; i++) scanf("%d",&arr[i]);

    dfs(0,0);
    printf("%d\n",ans);
}
