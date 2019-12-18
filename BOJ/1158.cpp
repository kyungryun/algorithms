#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n,k;
    queue<int> q;
    scanf("%d%d",&n,&k);
    for(int i=0 ; i<n ; i++)q.push(i+1);
    printf("<");
    while(!q.empty()){
        for(int i=0 ; i<k-1 ; i++){
            q.push(q.front());
            q.pop();
        }
        if(q.size() != 1) printf("%d, ",q.front());
        else printf("%d",q.front());
        q.pop();
    }
    printf(">");
}