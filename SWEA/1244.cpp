#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int c;
int ans;
int checked[1000000];
void dfs(char str[], int cnt){
  int num = atoi(str);
  if(checked[cnt] > num){
    return;
  }
  if(cnt == c){
    if(ans < num) ans = num;
    return;
  }

  checked[cnt] = num;
  int len = strlen(str);
  for(int i=0 ; i<len ; i++){
    for(int j=i+1 ; j<len ; j++){
      char t = str[i];
      str[i] = str[j];
      str[j] = t;
      dfs(str, cnt+1);
      t = str[i];
      str[i] = str[j];
      str[j] = t;
    }
  }
}
int main() {
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
      memset(checked, 0 ,sizeof(checked));
      ans = 0;
      char n[7];
      scanf("%s%d",n,&c);
      dfs(n,0);
      printf("#%d %d\n", t, ans);
    }
}
