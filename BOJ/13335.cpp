#include <cstdio>
#include <queue>

using namespace std;

int n,w,l;
int a[1001];
int main(){
    scanf("%d%d%d",&n,&w,&l);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
    queue<int> q;
    int time = 0;
    int weight = 0;
    for(int i=0 ; i<n ; i++){
        while(1){
            if(q.empty()){
                q.push(a[i]);
                time++;
                weight += a[i];
                break;
            }else if(q.size() == w){
                weight -= q.front();
                q.pop();
            }else{
                if(weight + a[i] > l){
                    q.push(0);
                    time++;
                }else{
                    q.push(a[i]);
                    time++;
                    weight += a[i];
                    break;
                }
            }
        }
    }
    printf("%d\n",time+w);
}
