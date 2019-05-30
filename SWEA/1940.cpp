#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  int d,c,acc,speed;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    d = 0;
    acc = 0;
    speed = 0;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
      scanf("%d",&c);
      if(c == 1 || c == 2){
        scanf("%d",&acc);
        if(c == 1){
          speed += acc;
        }else{
          if(speed - acc > 0) speed -= acc;
          else speed = 0;
        }
      }
      d += speed;
    }
    printf("#%d %d\n",t,d);
  }
}
