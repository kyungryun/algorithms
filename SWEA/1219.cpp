#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int l, ans;
  int tc;
  for(int t=1 ; t<=10 ; t++){
    ans = 0;
    int to, from;
    vector<vector<int> > v(100);
    queue<int> q;
    scanf("%d%d",&tc,&l);
    for(int i=0 ; i<l ; i++){
      scanf("%d%d",&from,&to);
      v[to].push_back(from);
    }
    int size = v[99].size();
    for(int i=0 ; i<size ; i++){
      q.push(v[99][i]);
    }
    while(!q.empty()){
      int idx = q.front();
      q.pop();
      if(idx == 0){
        ans = 1;
        break;
      }
      int size = v[idx].size();
      for(int i=0 ; i<size ; i++){
        q.push(v[idx][i]);
      }
    }

    printf("#%d %d\n",tc,ans);
  }
}
