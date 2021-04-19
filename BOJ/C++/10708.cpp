#include <cstdio>

int n,m;
int a[101],b[101],ans[101];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=m ; i++){
        scanf("%d",&a[i]);
    }

    for(int i=1 ; i<=m ; i++){
        int target = a[i];
        int cnt = 0;
        for(int j=1 ; j<=n ; j++) scanf("%d",&b[j]);
        for(int j=1 ; j<=n ; j++){
            if(target == b[j]) ans[j]++;
            else cnt++;
        }
        ans[a[i]] += cnt;
    }
    for(int i=1 ; i<=n ; i++) printf("%d\n",ans[i]);
}