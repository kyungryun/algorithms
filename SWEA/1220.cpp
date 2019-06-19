#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int ans,n;
  for(int t=1 ; t<=10 ; t++){
    int map[101][101];
    ans = 0;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
        scanf("%d",&map[i][j]);
      }
    }

    for(int j=0 ; j<n ; j++){
      int flag = 0;
      for(int i=0 ; i<n ; i++){
        if(flag == 0 && map[i][j] == 1) flag = 1;
        else if(flag == 1 && map[i][j] == 2) {
          ans++;
          flag = 0;
        }
      }
    }
    printf("#%d %d\n",t,ans);
  }
}
