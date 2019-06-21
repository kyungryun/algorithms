#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  int t,tc,n;
  scanf("%d",&t);
  for(int T=1 ; T<=t ; T++){
    map<int,int> score;
    scanf("%d",&tc);

    for(int i=0 ; i<1000 ; i++){
      scanf("%d",&n);
      score[n]++;
    }
    int max_cnt = -1;
    int max_score = 0;

    for(auto it = score.begin() ; it != score.end() ; it++){
      if(it->second > max_cnt){
        max_cnt = it->second;
        max_score = it->first;
      }else if(it->second == max_cnt){
        if(it->first > max_score) max_score = it->first;
      }
    }
    printf("#%d %d\n",tc,max_score);

  }
}
