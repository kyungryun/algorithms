#include <iostream>
#include <string>
#include <stack>
using namespace std;

int postfix(string str){
  stack<char> s;
  stack<int> n;
  string temp = "";
  for(int i=0 ; i<str.size() ; i++){
    if(isdigit(str[i])){
      temp+=str[i];
    }else if(str[i] == '('){
      s.push(str[i]);
    }else if(str[i] == ')'){
      while(s.top() != '('){
        temp += s.top();
        s.pop();
      }
      s.pop();
    }else{
      if(!s.empty()){
        if(str[i] == '*'){
          while(!s.empty() && s.top() == '*'){
            temp += s.top();
            s.pop();
          }
        }else if(str[i] == '+'){
          while(!s.empty() && s.top() != '('){
            temp += s.top();
            s.pop();
          }
        }
      }
      s.push(str[i]);
    }
  }
  if(!s.empty()) temp += s.top();

  for(int i=0 ; i<temp.size() ; i++){
    if(isdigit(temp[i])){
      n.push(temp[i] - '0');
    }else{
      if(temp[i] == '+'){
        int a = n.top();
        n.pop();
        a += n.top();
        n.pop();
        n.push(a);
      }else if(temp[i] == '*'){
        int a = n.top();
        n.pop();
        a *= n.top();
        n.pop();
        n.push(a);
      }
    }
  }
  return n.top();
}
int main() {
    for(int t=1 ; t<=10 ; t++){
      string str;
      int len;
      cin>>len;
      cin>>str;

      cout<<"#"<<t<<' '<<postfix(str)<<endl;
    }
}
