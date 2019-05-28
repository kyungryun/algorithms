#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  int ans;

  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    char c[11][2];
    int k[11];
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
      scanf("%s",c[i]);
      scanf("%d",&k[i]);
    }
    ans = 0;
    printf("#%d\n",t);
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<k[i] ; j++) {
        printf("%s",c[i]);
        cnt++;
        if(cnt == 10) {
          printf("\n");
          cnt=0;
        }
      }
    }
    printf("\n");
  }
}
