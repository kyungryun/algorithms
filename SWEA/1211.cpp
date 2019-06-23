#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int lad[101][101];
int MIN;
int dfs(int x, int y, int depth, int cnt){
  int nx = x;
  int ny = y;
  while(depth < 100){
    if(lad[ny][nx-1] == 1){
      while(lad[ny][nx-1] != 0) {
        nx--;
        cnt++;
      }
    }
    else if(lad[ny][nx+1] == 1){
      while(lad[ny][nx+1] != 0) {
        nx++;
        cnt++;
      }
    }
    ny++;
    depth++;
    cnt++;
  }
  return cnt;
}
int main() {
  int tc;
  int ans,cnt;
  for(int t=1 ; t<=10 ; t++){
    ans = 0;
    MIN = 987654321;
    scanf("%d",&tc);
    for(int i=0 ; i<100 ; i++){
      for(int j=0 ; j<100 ; j++){
        scanf("%d",&lad[i][j]);
      }
    }
    for(int i=0 ; i<100 ; i++){
      if(lad[0][i] == 1){
        cnt = dfs(i,1,1,0);
        if(cnt <= MIN){
          MIN = cnt;
          ans = i;
        }
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
