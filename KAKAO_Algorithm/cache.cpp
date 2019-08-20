#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int cacheSize;
  int n;
  int cities[100001];

  scanf("%d%d",&n,&cacheSize);

  for(int i=0 ; i<n ; i++){
    scanf("%d",&cities[i]);
  }
  int runtime = 0;
  int s = 0;
  vector<int> l;
  for(int i=0 ; i<n ; i++){
    if(cacheSize == 0){
      runtime = n*5;
      break;
    }else{
      vector<int>::iterator it = find(l.begin(),l.end(),cities[i]);
      if(it != l.end()){
        runtime++;
      }else{
        runtime+=5;
        if(cacheSize == l.size()){
          l.erase(l.begin());
        }
        if(l.size() != cacheSize) l.insert(l.end(),cities[i]);
      }
    }
  }
  printf("%d\n",runtime);
}
