#include <iostream>
#include <string>
using namespace std;

int main() {
  int tc,ans;
  for(int t=1 ; t<=10 ; t++){
    ans = 0;
    string str,substr;
    cin>>tc;
    cin>>substr;
    cin>>str;
    int idx = str.find(substr);
    while(idx != -1){
      ans++;
      idx = str.find(substr, idx+1);
    }
    printf("#%d %d\n",tc,ans);
  }
}
