#include <cstdio>
#include <stack>
using namespace std;

long long ans;
long long calc = 1;
int main(){
    char str[31];
    bool flag = true;
    stack<char> s;
    
    scanf("%s",str);
    for(int i=0; str[i] != 0; i++){
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
    if(flag) printf("%lld\n",ans);
    else printf("0\n");
}
