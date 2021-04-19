#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int N;
int map[51][51];
int dr[5] = {-1,1,0,0,0};
int dc[5] = {0,0,-1,1,0};
int drot[3] = {1,0,-1};
int ans = 987654321;
int visited[51][51][2];
int dir;
vector<pair<int, int>> fin;

bool isRot(int r, int c){
    for(int i=r ; i<3+r ; i++){
        for(int j=c ; j<3+c ; j++){
            if(map[i][j] == 1 || i < 0 || i>=N || j < 0 || j >= N) return false;
        }
    }
    return true;
}

void bfs(vector<pair<int,int>> &tree){
    queue<pair<pair<int,int>, pair<int, int>>> q;
    int ndir;
    if(tree[0].first == tree[1].first && tree[1].first == tree[2].first) ndir = 0;
    else ndir = 1;
    q.push(make_pair(make_pair(ndir,0),make_pair(tree[1].first,tree[1].second)));

    visited[tree[1].first][tree[1].second][ndir] = 1;

    while(!q.empty()){
        int ndir = q.front().first.first;
        int time = q.front().first.second;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(r == fin[1].first && c == fin[1].second && ndir == dir){
            ans = min(ans, time);
            continue;
        }

        if(ndir == 0){
            int nr =  r-1;
            int nc = c;
            if(nr >= 0 && nc - 1 >= 0 && nc + 1 < N && !visited[nr][c][ndir]){
                if(!map[nr][nc] && !map[nr][nc-1] && !map[nr][nc+1]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }

            nr = r+1;
            nc = c;
            if(nr < N && nc - 1 >= 0 && nc + 1 < N && !visited[nr][c][ndir]){
                if(!map[nr][nc] && !map[nr][nc-1] && !map[nr][nc+1]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }

            nr = r;
            nc = c - 1;
            int nnc = nc-1;
            if(nnc >= 0 && !visited[nr][nc][ndir]){
                if(!map[nr][nnc]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }
            nr = r;
            nc = c+1;
            nnc = nc+1;
            if(nnc < N && !visited[nr][nc][ndir]){
                if(!map[nr][nnc]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }
            if(isRot(r-1,c-1) && !visited[r][c][1]){
                visited[r][c][1] = 1;
                q.push(make_pair(make_pair(1,time+1),make_pair(r,c)));
            }
        }else{
            int nr =  r-1;
            int nnr = nr-1;
            int nc = c;
            if(nnr >= 0 && !visited[nr][c][ndir]){
                if(!map[nnr][nc]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }

            nr = r+1;
            nnr = nr+1;
            nc = c;
            if(nnr < N && !visited[nr][c][ndir]){
                if(!map[nnr][nc]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }

            nr = r;
            nc = c - 1;
            if(nc >= 0 && nr-1 >= 0 && nr+1 < N && !visited[nr][nc][ndir]){
                if(!map[nr][nc] && !map[nr-1][nc] && !map[nr+1][nc]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }
            nr = r;
            nc = c+1;
            if(nc < N && nr-1 >= 0 && nr+1 < N && !visited[nr][nc][ndir]){
                if(!map[nr][nc] && !map[nr-1][nc] && !map[nr+1][nc]){
                    visited[nr][nc][ndir] = 1;
                    q.push(make_pair(make_pair(ndir,time+1),make_pair(nr,nc)));
                }
            }
            if(isRot(r-1,c-1) && !visited[r][c][0]){
                visited[r][c][0] = 1;
                q.push(make_pair(make_pair(0,time+1),make_pair(r,c)));
            }
        }
    }
}
int main(){
    scanf("%d",&N);
    char a[51][51];
    for(int i=0 ; i<N ; i++){
        scanf("%s",a[i]);
    }
    vector<pair<int, int>> tree;
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(a[i][j] == 'B') {
                map[i][j] = 0;
                tree.push_back(make_pair(i,j));
            }
            else if(a[i][j] == 'E'){
                 map[i][j] = 0;
                 fin.push_back(make_pair(i,j));
             }
            else if(a[i][j] == '0') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
    if(fin[0].first == fin[1].first && fin[1].first == fin[2].first) dir = 0;
    else dir = 1;
    bfs(tree);

    printf("%d\n",ans == 987654321 ? 0 : ans);
}
