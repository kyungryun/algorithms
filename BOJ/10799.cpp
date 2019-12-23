#include <cstdio>

using namespace std;

char stack[100001];
char str[100001];

int main(){
    int ans = 0;
    int top = -1;
    scanf("%s",str);

    for(int i=0 ; str[i] != 0 ; i++){
        if(str[i] == '(') stack[++top] = str[i];
        else{
            top--;
            if(str[i-1] == '(') ans += (top+1);
            else ans++;
        }
    }
    printf("%d\n",ans);
}