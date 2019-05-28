#include <cstdio>

using namespace std;

int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
  int T;
  int n;
  int ans;
  int f_m,f_d,s_m,s_d;
  scanf("%d",&T);
  for(int t = 1 ; t<=T ; t++){
    ans = 0;
    scanf("%d%d%d%d",&f_m,&f_d,&s_m,&s_d);

    for(int i=f_m ; i< s_m ; i++){
      ans += month[i-1];
    }
    ans += (s_d-f_d+1);
    printf("#%d %d\n",t, ans);
  }
}
