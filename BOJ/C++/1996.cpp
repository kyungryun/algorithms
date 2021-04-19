#include <cstdio>
#include <queue>

using namespace std;

int n;
int map[1001][1001];
int dr[8] = {-1,-1,-1,0,1,1,1,0};
int dc[8] = {-1,0,1,1,1,0,-1,-1};

void bfs(){
    queue<pair<int, int>> q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(map[i][j] < 0) q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0 ; i<8 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if(map[nr][nc] < 0 ) continue;
            map[nr][nc] += (map[r][c])*(-1);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            char c;
            scanf(" %c",&c);
            if(c == '.') map[i][j] = 0;
            else map[i][j] = (c - '0')*(-1);
        }
    }
    bfs();
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(map[i][j] < 0) printf("*");
            else if(map[i][j] >= 10) printf("M");
            else printf("%d",map[i][j]);
        }
        printf("\n");
    }
}
