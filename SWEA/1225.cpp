#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;
int main() {
    int t;

    while(scanf("%d",&t) != -1){
      deque<int> dq;
      int tmp;
      for(int i=0 ; i<8 ; i++){
        scanf("%d",&tmp);
        dq.push_back(tmp);
      }
      int flag = 1;
      while(flag){
        for(int i=1 ; i<=5 ; i++){
          tmp = dq.front() - i;
          if(tmp < 0) {
            tmp = 0;
          }
          dq.pop_front();
          dq.push_back(tmp);
          if(dq.back() == 0) {
            flag = 0;
            break;
          }
        }
      }

      printf("#%d ",t);
      for(int i=0 ; i<8 ; i++) printf("%d ",dq.at(i));
      printf("\n");
    }
}
