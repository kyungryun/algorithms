#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int func(int num, int cnt){
  if(cnt == m - 1) return num;
  return func(num*n, cnt+1);
}
int main() {
  int tc;
  for(int t=1 ; t<=10 ; t++){
    int ans;
    scanf("%d",&tc);
    scanf("%d%d",&n,&m);
    ans = func(n,0);
    printf("#%d %d\n",tc,ans);
  }
}
