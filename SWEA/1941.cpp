#include <cstdio>

using namespace std;

int main(){
  int T;
  long long n,a,b;
  int ans;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    scanf("%lld%lld%lld",&n,&a,&b);
    long long min = 987654321;
    long long res;
    for(int r = 1 ; r<= n ;r++){
      for(int c = 1 ; c*r<=n ; c++){
        if(r >= c) res = a*(r-c) + b*(n-r*c);
        if(res < min) min = res;
      }
    }
    printf("#%d %lld\n",t, min);
  }
}
