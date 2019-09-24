#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int L,R,C;
int d[31][31][31];
bool visited[31][31][31];
int dir[6][3] = {{1,0,0},{0,1,0},{0,0,1}, {-1,0,0},{0,-1,0},{0,0,-1}};

int bfs(int sh, int sr, int sc){
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(sh,make_pair(sr,sc)));
    visited[sh][sr][sc] = true;
    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int h = q.front().first;
        q.pop();
        for(int i=0 ; i<6 ; i++){
            int nh = h + dir[i][0];
            int nr = r + dir[i][1];
            int nc = c + dir[i][2];

            if(nr >= 0 && nc >= 0 && nh >= 0 && nr < R && nc < C && nh < L){
                if(d[nh][nr][nc] == 0 && !visited[nh][nr][nc]){
                    d[nh][nr][nc] = d[h][r][c] + 1;
                    visited[nh][nr][nc] = true;
                    q.push(make_pair(nh,make_pair(nr,nc)));
                }
            }
        }
    }
}
int main(){
    while(1){
        int sr,sc,sh,er,ec,eh;
        memset(visited, false, sizeof(visited));
        scanf("%d%d%d",&L,&R,&C);
        if(L == 0 && R == 0 && C == 0) break;
        for(int i=0 ; i<L ; i++){
            for(int j=0 ; j<R ; j++){
                for(int k=0 ; k<C ; k++){
                    char c;
                    scanf(" %c",&c);
                    if(c == '.') d[i][j][k] = 0;
                    else if(c == '#') d[i][j][k] = 1;
                    else if(c == 'S'){
                        d[i][j][k] = 0;
                        sr = j, sc = k, sh = i;
                    }else if(c == 'E'){
                        d[i][j][k] = 0;
                        er = j, ec = k, eh = i;
                    }
                }
            }
        }
        bfs(sh,sr,sc);
        if(visited[eh][er][ec]){
            printf("Escaped in %d minute(s).\n",d[eh][er][ec]);
        }else printf("Trapped!\n");
    }

}
