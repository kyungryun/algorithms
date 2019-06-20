#include <cstdio>
using namespace std;

int main() {
  int tc,ans;
  int row,col,ldia,rdia;
  for(int t=1 ; t<=10 ; t++){
    row = col = ldia = rdia = 0;
    int max = -1;
    int map[101][101];
    scanf("%d",&tc);
    for(int i=0 ; i<100 ; i++){
      for(int j=0 ; j<100 ; j++){
        scanf("%d",&map[i][j]);
      }
    }
    for(int i=0 ; i<100 ; i++){
      col = row = 0;
      for(int j=0 ; j<100 ; j++){
        col += map[j][i];
        row += map[i][j];
      }
      ldia += map[i][i];
      rdia += map[i][99-i];
      if(col > row) {
        if(col > max) max = col;
      }else{
        if(row > max) max = row;
      }
    }
    if(ldia > rdia){
      if(ldia > max) max = ldia;
    }else{
      if(rdia > max) max = rdia;
    }

    printf("#%d %d\n",tc,max);
  }
}
