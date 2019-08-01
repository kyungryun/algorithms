#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N[2][500002];
int main(){
    int k;
    int n;
    scanf("%d%d",&n,&k);
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<500001 ; j++){
            N[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        int chk = time%2;
        q.pop();
        if(now < 0 || now > 500000) continue;
        if(N[chk][now] != -1) continue;
        N[chk][now] = time;
        q.push(make_pair(now+1,time+1));
        q.push(make_pair(now-1,time+1));
        q.push(make_pair(now*2,time+1));
    }
    int i=0;
    while(1){
        int sum = k + (i*(i+1))/2;
        if(sum > 500000) {
            i = -1;
            break;
        }
        if(N[i%2][sum] != -1 && N[i%2][sum] <= i){
            break;
        }
        i++;
    }
    if(i > 500000) i = -1;
    printf("%d\n",i);
}
