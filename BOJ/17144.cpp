#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R,C,T;
int A[1001][1001];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
vector<pair<int, int>> air;
void bfs(){
    queue<pair<int, pair<int,int>> > q;
    for(int i=0 ; i<R; i++){
        for(int j=0 ; j<C ; j++){
            if(A[i][j] > 0) {
                q.push(make_pair(A[i][j]/5, make_pair(i,j)));
            }
        }
    }

    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int spread = q.front().first;
        q.pop();
        int cnt = 0;
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || A[nr][nc] == -1) continue;
            A[nr][nc] += spread;
            cnt++;
        }
        A[r][c] -= spread*cnt;
    }
    int r = air[0].first-1;
    int c = air[0].second;
    for(int i=r ; i>0 ; i--){
        A[i][0] = A[i-1][0];
    }
    for(int i=0 ; i<C-1 ; i++){
        A[0][i] = A[0][i+1];
    }
    for(int i=0 ; i<r+1 ; i++){
        A[i][C-1] = A[i+1][C-1];
    }
    for(int i=C-1 ; i>c+1 ; i--){
        A[r+1][i] = A[r+1][i-1];
    }
    A[r+1][c+1] = 0;

    r = air[1].first+1;
    for(int i=r ; i<R-1 ; i++){
        A[i][0] = A[i+1][0];
    }
    for(int i=0 ; i<C-1 ; i++){
        A[R-1][i] = A[R-1][i+1];
    }
    for(int i=R-1 ; i>=r ; i--){
        A[i][C-1] = A[i-1][C-1];
    }
    for(int i=C-1 ; i>c+1 ; i--){
        A[r-1][i] = A[r-1][i-1];
    }
    A[r-1][c+1] = 0;

}
int main(){
    scanf("%d%d%d",&R,&C,&T);

    for(int i=0 ; i<R ; i++){
        for(int j=0 ; j<C ; j++){
            scanf("%d",&A[i][j]);
            if(A[i][j] == -1) air.push_back(make_pair(i,j));
        }
    }
    for(int t=0 ; t<T ; t++){
        bfs();
        /*printf("\n");
        for(int i=0 ; i<R ; i++){
            for(int j=0 ; j<C ; j++){
                printf("%d ",A[i][j]);
            }
            printf("\n");
        }*/
    }
    int ans = 0;
    for(int i=0 ; i<R ; i++){
        for(int j=0 ; j<C ; j++){
            if(A[i][j] > 0) ans += A[i][j];
        }
    }
    printf("%d\n",ans);
}
