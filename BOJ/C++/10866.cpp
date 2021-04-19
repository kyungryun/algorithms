#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;

int main(){
    deque<int> dq;
    int T, n;
    char op[50];
    scanf("%d",&T);
    for(int i=0 ; i<T ; i++){
        scanf("%s", op);
        if(!strcmp(op,"push_back")){
            scanf("%d",&n);
            dq.push_back(n);
        }
        if(!strcmp(op,"push_front")){
            scanf("%d",&n);
            dq.push_front(n);
        }
        if(!strcmp(op,"pop_front")){
            if(dq.empty()) printf("-1\n");
            else{
                printf("%d\n",dq.front());
                dq.pop_front();
            }
        }
        if(!strcmp(op,"pop_back")){
            if(dq.empty()) printf("-1\n");
            else{
                printf("%d\n",dq.back());
                dq.pop_back();
            }
        }
        if(!strcmp(op,"size")) printf("%d\n",dq.size());
        if(!strcmp(op,"empty")) printf("%d\n",dq.empty());
        if(!strcmp(op,"front")){
            if(dq.empty()) printf("-1\n");
            else printf("%d\n",dq.front());
        }
        if(!strcmp(op,"back")){
            if(dq.empty()) printf("-1\n");
            else printf("%d\n",dq.back());
        }
    }
}
