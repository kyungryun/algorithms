#include <cstdio>
#include <stack>
using namespace std;

stack<char> a;
stack<char> b;
char l[1000001];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",l);
        for(int i=0 ; l[i] != 0 ; i++){
            char c = l[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) a.push(c);
            if(c == '<' && !a.empty()){
                b.push(a.top());
                a.pop();
            }
            if(c == '>' && !b.empty()){
                a.push(b.top());
                b.pop();
            }
            if(c == '-' && !a.empty()){
                a.pop();
            }
        }
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        while(!b.empty()){
            printf("%c",b.top());
            b.pop();
        }
        printf("\n");
    }
}
