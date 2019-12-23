#include <cstdio>

using namespace std;

char str[100001];
int top, ans;
int main(){
    
    scanf("%s",str);

    for(int i=0 ; str[i] != 0 ; i++){
        if(str[i] == '(') top++;
        else{
            top--;
            if(str[i-1] == '(') ans += top;
            else ans++;
        }
    }
    printf("%d\n",ans);
}