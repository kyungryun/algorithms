#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    int arr[11][11]={0,};
    scanf("%d",&n);

    int num = n;
    int r = 0;
    int c = -1;
    int cnt = 1;
    int dir = 1;
    while(true){
      if(num == 0) break;
      for(int i=0 ; i<num ; i++){
        c += dir;
        arr[r][c] = cnt;
        cnt++;
      }
      num--;
      for(int i=0 ; i<num ; i++){
        r += dir;
        arr[r][c] = cnt;
        cnt++;
      }
      dir *= -1;
    }

    printf("#%d\n",t);
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
        printf("%d ",arr[i][j]);
      }
      printf("\n");
    }
  }
}
