#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int s[21];
int m;

int contain(int n){
    return s[n];
}
void add(int n){
    s[n] = 1;
}
void remove(int n){
    s[n] = 0;
}
void empty(){
    memset(s,0,sizeof(s));
}
void all(){
    for(int i=1 ; i<=20 ; i++){
        s[i] = 1;
    }
}
int main(){
    scanf("%d",&m);
    char oper[10];
    int n;
    while(m--){
        scanf("%s",oper);
        if(strcmp(oper, "add") == 0){
            scanf("%d",&n);
            if(!contain(n)) add(n);
        }else if(strcmp(oper, "remove") == 0){
            scanf("%d",&n);
            if(contain(n)) remove(n);
        }else if(strcmp(oper, "check") == 0){
            scanf("%d",&n);
            if(contain(n)) printf("1\n");
            else printf("0\n");
        }else if(strcmp(oper, "toggle") == 0){
            scanf("%d",&n);
            if(contain(n)) remove(n);
            else add(n);
        }else if(strcmp(oper, "all") == 0){
            all();
        }else if(strcmp(oper, "empty") == 0){
            empty();
        }
    }
}
