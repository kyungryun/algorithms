#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int len;
  for(int t=1 ; t<=10 ; t++){
    int ans = 0;
    int apt[1001];
    scanf("%d",&len);

    for(int i=0 ; i<len ; i++){
      scanf("%d",&apt[i]);
    }
    int top = *max_element(apt, apt + len);
    while(top > 0){
      for(int i=2 ; i<len-2 ; i++){
        if(apt[i] >= top){
          if(top <= apt[i+1] || top <= apt[i+2] ||
             top <= apt[i-1] || top <= apt[i-2]) continue;
          else{
            ans++;
            printf("%d floor %d top\n",apt[i],top);
          }
        }
      }
      top--;
    }
    printf("#%d %d\n",t,ans);

  }
}
