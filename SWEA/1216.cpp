#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
  int tc;
  for(int t=1 ; t<=10 ; t++){
    int max = -1;
    scanf("%d",&tc);
    char map[101][101];
    for(int i=0 ; i<100 ; i++){
      scanf("%s",map[i]);
    }
    int len = 100;
    while(1){
      if(len == 1 || max != -1) break;

      for(int j=0 ; j<100 ; j++){
        for(int i=0 ; i<=100-len ; i++){
          int flag = 0;
          for(int k=0 ; k<len/2 ; k++){
            if(map[j][i+k] != map[j][i + (len - k - 1)]) {
              flag = 1;
              break;
            }
          }
          if(flag == 0){
            if(len > max) max = len;
            break;
          }
        }
        for(int i=0 ; i<=100-len ; i++){
          int flag = 0;
          for(int k=0 ; k<len/2 ; k++){
            if(map[i+k][j] != map[i + (len - k - 1)][j]) {
              flag = 1;
              break;
            }
          }
          if(flag == 0){
            if(len > max) max = len;
            break;
          }
        }
      }
      len--;
    }
    printf("#%d %d\n",tc,max);
  }
}
