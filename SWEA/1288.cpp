#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  int ans;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    ans = 0;
    int num[11] = {0,};
    char buf[10];
    scanf("%d",&n);
    int idx=1;
    int flag = 0;
    while(true){
      sprintf(buf,"%d",n*idx);
      for(int i=0 ; buf[i] != '\0' ; i++){
        num[buf[i] - 48]++;
      }
      int i;
      for(i=0 ; i<10 ; i++){
        if(num[i] == 0){
          idx++;
          break;
        }
      }
      if(i == 10) break;
    }
    printf("#%d %d\n",t, idx*n);
  }
}
