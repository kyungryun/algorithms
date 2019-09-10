#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    stack<char> s;
    long long ans = 0;
    long long calc = 1;
    bool flag = true;
    cin>>str;
    for(int i=0;  i<str.size() ; i++){
        if(str[i] == '(' || str[i] == '['){
            if(str[i] == '(') calc *=2;
            else calc *= 3;
            s.push(str[i]);
        }else{
            if(!s.empty()){
                if((str[i] == ')' && s.top() == '(') ||
                   (str[i] == ']' && s.top() == '[')){
                    if(str[i] == ')'){
                        if(str[i-1] == '(') ans += calc;
                        calc /= 2;
                    }else if(str[i] == ']'){
                        if(str[i-1] == '[') ans += calc;
                        calc /= 3;
                    }
                    s.pop();
                }else{
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
    }
    if(!s.empty()) flag = false;
    if(flag) cout<<ans<<"\n";
    else cout<<0<<"\n";
}
