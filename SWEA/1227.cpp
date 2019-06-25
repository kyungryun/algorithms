#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int maze[101][101];
int ans;
int bfs(int r, int c){
  queue<pair<int,int>> q;
  q.push(make_pair(r,c));
  while(!q.empty()){
    int rr = q.front().first;
    int cc = q.front().second;
    if(maze[rr][cc] == 3) {
      return 1;
    }
    for(int i=0 ; i<4 ; i++){
      int nr = rr + dr[i];
      int nc = cc + dc[i];
      if(nr < 0 || nr > 100 || nc <0 || nc > 100 || maze[nr][nc] == 1) continue;
      if(maze[nr][nc] == 0 || maze[nr][nc] == 3){
        q.push(make_pair(nr,nc));
      }
    }
    maze[rr][cc] = 2;
    q.pop();
  }
  return 0;
}
int main(){
  int tc;
  int r,c;
  for(int t=1 ; t<=10 ; t++){
    scanf("%d",&tc);

    for(int i=0 ; i<100 ; i++){
      for(int j=0 ; j<100 ; j++){
        scanf("%1d",&maze[i][j]);
        if(maze[i][j] == 2){
          r = i;
          c = j;
        }
      }
    }
    printf("#%d %d\n",tc,bfs(r,c));
  }
}
