#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Space{
    int r;
    int c;
    int range;
}s[6];
int n,m,k;
int map[101][101];
int tmp[101][101];
int ans = 987654321;
vector<int> p;
bool sel[6];
void print(){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            printf("%d ",tmp[i][j]);
        }
        printf("\n");
    }
}
void mapCopy(int (*a)[101], int (*b)[101]){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            a[i][j] = b[i][j];
        }
    }
}
int calc(){
    int MIN = 1e9;
    for(int i=1 ; i<=n ; i++){
        int res = 0;
        for(int j=1 ; j<=m ; j++){
            res += tmp[i][j];
        }
        MIN = min(res,MIN);
    }
    return MIN;
}
void rot(int r, int c, int range){
    int tmap[101][101];
    tmap[r][c] = tmp[r][c];
    for(int i=1 ; i<=range ; i++){
        int nr = r-i;
        for(int j=c-i ; j<c+i ; j++){
            tmap[nr][j+1] = tmp[nr][j];
        }
        int nc = c+i;
        for(int j=r-i ; j<r+i ; j++){
            tmap[j+1][nc] = tmp[j][nc];
        }
        nr = r+i;
        for(int j=c+i ; j>c-i ; j--){
            tmap[nr][j-1] = tmp[nr][j];
        }
        nc = c-i;
        for(int j=r+i ; j>r-i ; j--){
            tmap[j-1][nc] = tmp[j][nc];
        }
    }
    for(int i=r-range ; i<=r+range ; i++){
        for(int j=c-range ; j<=c+range ; j++){
            tmp[i][j] = tmap[i][j];
        }
    }
}

void dfs(int cnt){
    if(cnt == k){
        mapCopy(tmp, map);
        for(int i=0 ; i<p.size() ; i++){
            rot(s[p[i]].r,s[p[i]].c,s[p[i]].range);
        }
        ans = min(calc(),ans);
        return;
    }

    for(int i=0 ; i<k ; i++){
        if(sel[i]) continue;
        sel[i] = true;
        p.push_back(i);
        dfs(cnt+1);
        sel[i] = false;
        p.pop_back();
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0 ; i<k ; i++){
        scanf("%d%d%d",&s[i].r,&s[i].c,&s[i].range);
        s[i].r;
        s[i].c;
    }
    dfs(0);
    printf("%d\n",ans);
}
