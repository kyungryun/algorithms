#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n;
    int num;
    char oper[100];
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        scanf("%s",oper);

        if(strcmp(oper, "push")  == 0){
            scanf("%d",&num);
            q.push(num);
        }else if(strcmp(oper, "pop") == 0){
            if(!q.empty()){
                printf("%d\n",q.front());
                q.pop();
            }else{
                printf("-1\n");
            }
        }else if(strcmp(oper, "front") == 0){
            if(!q.empty()){
                printf("%d\n",q.front());
            }else printf("-1\n");
        }else if(strcmp(oper, "back") == 0){
            if(!q.empty()){
                printf("%d\n",q.back());
            }else printf("-1\n");
        }else if(strcmp(oper, "empty") == 0){
            if(q.empty()){
                printf("1\n");
            }else printf("0\n");
        }else if(strcmp(oper, "size") == 0){
            printf("%d\n",q.size());
        }
    }
}
