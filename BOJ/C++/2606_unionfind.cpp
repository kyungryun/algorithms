#include <cstdio>

int n,m;
int ans = 0;
int group[101];
int find(int x){
    if(group[x] == x) return x;
    return group[x] = find(group[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    group[a] = b;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1 ; i<=n ; i++){
        group[i] = i;
    }
    for(int i=0 ; i<m ; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        merge(a,b);
    }

    for(int i=2 ; i<=n ; i++){
        if(find(1) == find(i)) ans++;
    }
    printf("%d\n",ans);
}
