#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int lad[101][101];

int dfs(int x, int y, int depth){
  int nx = x;
  int ny = y;
  while(depth < 100){
    if(lad[ny][nx-1] == 1){
      while(lad[ny][nx-1] != 0) {
        nx--;
      }
    }
    else if(lad[ny][nx+1] == 1){
      while(lad[ny][nx+1] != 0) {
        nx++;
      }
    }
    ny++;
    if(lad[ny][nx] ==2) return 1;
    depth++;
  }
  return 0;
}
int main() {
  int tc;
  int ans;
  for(int t=1 ; t<=10 ; t++){

    scanf("%d",&tc);
    for(int i=0 ; i<100 ; i++){
      for(int j=0 ; j<100 ; j++){
        scanf("%d",&lad[i][j]);
      }
    }
    for(int i=0 ; i<100 ; i++){
      if(lad[0][i] == 1){
        if(dfs(i,1,1)){
          ans = i;
          break;
        }
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
