#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int n;
long long a[4001],b[4001],c[4001],d[4001],ga[16000001],gb[16000001];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
    }
    int idx = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            ga[idx] = a[i]+b[j];
            gb[idx++] = c[i]+d[j];
        }
    }

    sort(gb, gb+n*n);
    ans = 0;
    for(int i=0 ; i<n*n ; i++){
        long long lower = lower_bound(gb,gb+n*n,-(ga[i])) - gb;
        long long upper = upper_bound(gb,gb+n*n,-(ga[i])) - gb;

        if(ga[i] + gb[lower] == 0) ans += upper-lower;
    }
    printf("%lld\n",ans);

}
