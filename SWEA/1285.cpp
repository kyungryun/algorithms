#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    int stone[1001];
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
      scanf("%d",&stone[i]);
    }

    int min = 100000;
    int cnt = 0;
    int dist;
    for(int i=0 ; i<n ; i++){
      if(stone[i] < 0){
        stone[i] *= -1;
        dist = stone[i];
      }else{
        dist = stone[i];
      }
      if(dist < min) min = dist;
    }
    for(int i=0 ; i<n ; i++){
      if(stone[i] == min) cnt++;
    }
    printf("#%d %d %d\n",t,min, cnt);
  }
}
