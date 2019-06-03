#include <cstdio>
#include <cstring>
char num[10][8] = {"0001101",
                  "0011001",
                  "0010011",
                  "0111101",
                  "0100011",
                  "0110001",
                  "0101111",
                  "0111011",
                  "0110111",
                  "0001011"};

int main() {
    int T;
    int n,m;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {

      int arr[51][101];
      int encode[8];
      char code[8][8];

      scanf("%d%d",&n,&m);
      for(int i=1 ;i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            scanf("%1d",&arr[i][j]);
        }
      }
      int start = -1;
      int row;
      int last = 0;

      for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
          if(arr[i][j] == 1){
            if(start == -1) {
              start = j;
              row = i;
            }else {
              last = j - start + 1;
            }
          }
          if(last > 54) break;
        }
      }
    //  printf("%d %d\n",start, last);
      start = start - (56-last);
      for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<7 ; j++){
          code[i][j] = arr[row][start + j + i*7] + '0';
        }
      }
      for(int i=0 ; i<8 ; i++){
        //printf("%s\n",code[i]);
        for(int j=0 ; j<10 ; j++){
          if(strcmp(code[i],num[j]) == 0){
            encode[i] = j;
          }
        }
      }
      int vaild = (encode[0] + encode[2] + encode[4] + encode[6])*3 +
            (encode[1] + encode[3] + encode[5]) + encode[7];
      int ans = 0;
    //  printf("%d\n",vaild);
      if(vaild%10 == 0){
        for(int i=0 ; i<8 ; i++){
          ans += encode[i];
        }
      }
      printf("#%d %d\n", t, ans);
    }
}
