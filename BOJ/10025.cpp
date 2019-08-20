#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;

int point[1000001];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0 ; i<n ; i++){
        int g,x;
        scanf("%d%d",&g,&x);
        point[x] = g;
    }
    k = k*2+1;
    int sum = 0;
    int ans = 0;
    for(int i=0 ; i<1000000 ; i++){
        if(i>=k) sum -= point[i-k];
        sum+=point[i];
        ans = max(ans, sum);
    }
    printf("%d\n",ans);
}
