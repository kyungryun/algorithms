#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int node[101];
void dfs(int index){
  if(node[index] == 0) return;

  dfs(index*2);
  printf("%c",node[index]);
  dfs(index*2+1);
}
int main() {
  int N;
  for(int T=1 ; T<=10 ; T++){
    scanf("%d",&N);
    for(int i=0 ; i<101 ; i++)node[i] = 0;
    for(int i=1 ; i<=N ; i++){
      int n;
      char c;
      scanf("%d %c",&n,&c);
      if((N%2==0 &&(i < N/2)) || (N%2 == 1 && i<=(N-1)/2)){
        scanf("%*d %*d");
      }else if(N%2==0 && i==N/2){
        scanf("%*d");
      }
      node[n] = c;
    }
    printf("#%d ",T);
    dfs(1);
    printf("\n");
  }
}
