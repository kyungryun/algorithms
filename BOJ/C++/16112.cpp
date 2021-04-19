#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,k;
int arr[300001];
long long ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr, arr+n);
    long long exp = 0;
    for(int i=0 ; i<n ; i++){
        ans += (long long)arr[i]*min(i,k);

    }
    printf("%lld\n",ans);
}
