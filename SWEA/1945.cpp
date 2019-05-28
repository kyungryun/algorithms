#include <cstdio>

using namespace std;

int main(){
  int T;
  int n;
  int a,b,c,d,e;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    a=b=c=d=e=0;
    scanf("%d",&n);
    while(n>=2){

      if(n%11 == 0){
        e++;
        n /= 11;
      }
      if(n%7 == 0){
        d++;
        n/=7;
      }
      if(n%5 == 0){
        c++;
        n/=5;
      }
      if(n%3 == 0){
        b++;
        n/=3;
      }
      if(n%2 == 0){
        a++;
        n/=2;
      }

    }
    printf("#%d %d %d %d %d %d\n",t,a,b,c,d,e);
  }
}
