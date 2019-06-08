#include <cstdio>
int main() {
    int T;
    int n;

    for(int t = 1; t <= 10; t++) {
      int ans = 0;
      int pass[101];
      int temp[101];
      int before;
      scanf("%d",&n);
      before = n;
      for(int i=0 ; i<n ; i++){
        scanf("%1d",&pass[i]);
        temp[i] = pass[i];
      }
      while(1){
        for(int i=0 ; i<n-1 ; i++){
          if(temp[i] == temp[i+1]){
            int j;
            for(j=0 ; j<i ; j++);
            for(int k=i+2 ; k<n ; k++) temp[j++] = temp[k];
            n-=2;
            break;
          }
        }
        if(before == n) break;
        else before = n;
      }

      printf("#%d ", t);
      for(int i=0; i<n ; i++)printf("%d",temp[i]);
      printf("\n");
    }
}
