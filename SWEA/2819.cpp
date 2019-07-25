#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int map[4][4];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int num[7];
set<int> s;
void dfs(int x, int y, int cnt){
    if(cnt == 7){
        int res = 0;
        for(int i=0 ; i<7 ; i++){
            res = res*10 + num[i];
        }
        s.insert(res);
        return;
    }
    num[cnt] = map[x][y];
    for(int i=0 ; i<4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        dfs(nx,ny,cnt+1);
    }
}
int main(){
    int t;
    scanf("%d",&t);

    for(int T=1 ; T<=t ; T++){
        s.clear();
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                dfs(i,j,0);
            }
        }
        printf("#%d %d\n",T,s.size());
    }
}
