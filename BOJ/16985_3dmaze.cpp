#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
int board[5][5][5];
int sim[5][5][5];
int rot[4][5][5][5];
int dir[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
vector<int> p;
bool visited[5];
int MIN = INF;
void rotate(){
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
            for(int k=0 ; k<5 ; k++){
                rot[0][i][j][k] = board[i][j][k];
            }
        }
    }
    for(int r=1 ; r<4 ; r++){
        for(int i=0 ; i<5 ; i++){
            for(int j=0 ; j<5 ; j++){
                for(int k=0 ; k<5 ; k++){
                    rot[r][i][j][k] = rot[r-1][i][k][4-j];
                }
            }
        }
    }
}
void start(){
    bool checked[5][5][5] = {false,};
    int dist[5][5][5] = {0,};

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0,make_pair(0,0)));
    checked[0][0][0] = true;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second.first;
        int h = q.front().second.second;
        q.pop();

        for(int i=0 ; i<6 ; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            int nh = h + dir[i][2];

            if(nr < 0 || nc < 0 || nh < 0 || nr >=5 || nc >= 5|| nh >= 5)continue;
            if(sim[nh][nr][nc] == 0 || checked[nh][nr][nc]) continue;
            checked[nh][nr][nc] = true;
            dist[nh][nr][nc] = dist[h][r][c]+1;
            q.push(make_pair(nr,make_pair(nc,nh)));

        }
    }
    if(checked[4][4][4]){
        MIN = min(MIN, dist[4][4][4]);
    }
}
void copy(int r, int h){
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
            sim[h][i][j] = rot[r][p[h]][i][j];
        }
    }
}
void dfs(int cnt){
    if(cnt == 5){
        for(int r1=0 ; r1<4 ; r1++){
            copy(r1, 0);
            if(sim[0][0][0] == 0) continue;
            for(int i=0 ; i<4 ; i++){
                copy(i,1);
                for(int j=0 ; j<4 ; j++){
                    copy(j,2);
                    for(int k=0 ; k<4 ; k++){
                        copy(k,3);
                        for(int l=0 ; l<4 ; l++){
                            copy(l,4);
                            if(sim[4][4][4]) start();
                        }
                    }
                }
            }
        }
    }
    for(int i=0 ; i<5 ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        p.push_back(i);
        dfs(cnt+1);
        p.pop_back();
        visited[i] = false;
    }
}
int main(){
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
            for(int k=0 ; k<5 ; k++){
                scanf("%d",&board[i][j][k]);
            }
        }
    }
    rotate();
    dfs(0);
    printf("%d\n",MIN==INF ? -1 : MIN);
}
