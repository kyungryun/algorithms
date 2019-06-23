#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
int main() {
  int l, ans;
  char c;
  for(int t=1 ; t<=10 ; t++){
    ans = 1;
    stack<char> s;
    string str;
    scanf("%d",&l);
    cin>>str;
    for(int i=0 ; i<l ; i++){
      if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<'){
        s.push(str[i]);
      }else{
        if((s.top() == '(' && str[i] == ')') ||
          (s.top() == '{' && str[i] == '}') ||
          (s.top() == '[' && str[i] == ']') ||
          (s.top() == '<' && str[i] == '>')) s.pop();
        else ans = 0;
      }
    }
    printf("#%d %d\n",t,ans);
  }
}
