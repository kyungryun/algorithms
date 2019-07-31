#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ans = 987654321;
int paper[6];
void dfs(int cnt, int r, int c, int sel,vector<vector<int>> map){

    if(cnt > ans) return;
    bool isZero = true;
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            if(map[i][j] == 1){
                isZero = false;
                break;
            }
        }
        if(!isZero) break;
    }

    if(isZero){
        ans = min(ans, cnt);
        if(ans == -1) ans = 0;
        return;
    }
    for(int i=r ; i<r + sel ; i++){
        for(int j=c ; j<c + sel ; j++){
            if(i>=10 || j>=10 || map[i][j] ==0) return;
            map[i][j] = 0;
        }
    }
    int nr,nc;
    bool flag = false;

    for(int i=0 ; i<10  ;i++){
        for(int j=0 ; j<10 ; j++){
            if(map[i][j] == 1){
                nr = i;
                nc = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    for(int i=5 ; i>=1 ; i--){
        if(paper[i] == 5) continue;
        paper[i]++;
        dfs(cnt+1, nr, nc, i, map);
        paper[i]--;
    }
}
int main(){
    //int map[11][11];
    vector<vector<int> > map(10, vector<int>(10, 0));
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    dfs(-1,0,0,0,map);
    if(ans == 987654321) ans = -1;
    printf("%d\n",ans);
}
