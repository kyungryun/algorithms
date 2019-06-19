#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
  int len,ans;
  for(int t=1 ; t<=10 ; t++){
    ans = 0;
    scanf("%d",&len);
    char map[9][9];
    for(int i=0 ; i<8 ; i++){
      scanf("%s",map[i]);
    }

    for(int j=0 ; j<8 ; j++){
      for(int i=0 ; i<=8-len ; i++){
        int flag = 0;
        for(int k=0 ; k<len/2 ; k++){
          if(map[j][i+k] != map[j][i + (len - k - 1)]) {
            flag = 1;
            break;
          }
        }
        if(flag == 0) ans++;
      }
      for(int i=0 ; i<=8-len ; i++){
        int flag = 0;
        for(int k=0 ; k<len/2 ; k++){
          if(map[i+k][j] != map[i+(len-k-1)][j]) {
            flag = 1;
            break;
          }
        }
        if(flag == 0) ans++;
      }
    }
    printf("#%d %d\n",t,ans);
  }
}
