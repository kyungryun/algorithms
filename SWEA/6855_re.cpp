#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n,k;
int ans;
int home[100000];
int dist[100000];
bool comp(int a, int b){
    return a > b;
}
int main(){
    int T;

    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        ans = 0;
        memset(dist, 0, sizeof(dist));
        scanf("%d%d",&n,&k);
        for(int i=0 ; i<n ; i++) scanf("%d",&home[i]);

        if(n-k <=0){
            ans = 0;
        }else if(k == 1){
            ans = home[n-1] - home[0];
        }else{
            for(int i=1 ; i<n ; i++) dist[i-1] = home[i] - home[i-1];
            sort(dist, dist + n-1, comp);
            for(int i=k-1 ; i<n-1 ; i++) ans += dist[i];
        }

        printf("#%d %d\n",t, ans);
    }
}
