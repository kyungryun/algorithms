#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
  string str;
  cin>>str;
  int score[3];
  int cnt = -1;
  for(int i=0 ; i<str.size() ; i++){
    if(isdigit(str[i])){
      cnt++;
      if(str[i+1] == '0'){
        score[cnt] = 10*(str[i]-'0');
        i++;
      }else{
        score[cnt] = str[i] - '0';
      }
    }else if(str[i] == 'S'){
      score[cnt] = pow(score[cnt],1);
    }else if(str[i] == 'D'){
      score[cnt] = pow(score[cnt],2);
    }else if(str[i] == 'T'){
      score[cnt] = pow(score[cnt],3);
    }else if(str[i] == '*'){
      if(cnt == 0) score[cnt]*=2;
      else {
        score[cnt]*=2;
        score[cnt-1]*=2;
      }
    }else if(str[i] == '#'){
      score[cnt]*=-1;
    }
  }
  int ans = 0;
  for(int i=0 ; i<3 ; i++){
    ans += score[i];
  }
  cout<<ans<<endl;
}
