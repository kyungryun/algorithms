#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string s[1001];
int inorder(int num){
  if(!isdigit(s[num][1])){
    int a = 0;
    int b = 0;
    int i = 3;
    while(s[num][i] != ' '){
      a*=10;
      a+= (s[num][i] - '0');
      i++;
    }
    i++;
    while(s[num].size() > i){
      b*=10;
      b+=(s[num][i]-'0');
      i++;
    }
    if(a == 0 || b == 0) return 0;
    else{
      if(inorder(a) + inorder(b) > 1) return 1;
      else return 0;
    }
  }else{
    if(s[num].size() == 2) return 1;
    else return 0;
  }
}
int main() {
  int N;
  for(int T=1 ; T<=10 ; T++){

    scanf("%d",&N);

    for(int i=0 ; i<N ; i++){
      int n;
      string str;

      scanf("%d",&n);
      getline(cin, str);
      s[n] = str;
    }
    int ans = inorder(1);
    printf("#%d %d\n",T, ans);

  }
}
