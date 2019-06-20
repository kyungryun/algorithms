#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int cnt;

  for(int t=1 ; t<=10 ; t++){
    vector <int> v;
    scanf("%d",&cnt);
    int tmp;
    for(int i=0 ; i<100 ; i++) {
      scanf("%d",&tmp);
      v.push_back(tmp);
    }
    int MIN,MAX;
    while(cnt > 0){
      MIN = *min_element(v.begin(), v.end());
      MAX = *max_element(v.begin(), v.end());
      for(int i=0 ; i<100 ; i++){
        if(v[i] == MIN) {
          v[i]++;
          break;
        }
      }
      for(int i=0 ; i<100 ; i++){
        if(v[i] == MAX){
          v[i]--;
          break;
        }
      }
      cnt--;
    }
    int ans = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    printf("#%d %d\n",t,ans);
  }
}
