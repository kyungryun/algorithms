#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m,n;
int arr[100001];

bool comp(int a, int b){
    return a > b;
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0 ; i<n ; i++) scanf("%d",&arr[i]);

    sort(arr, arr + n);
    long long sum = -m;
    for(int i=0 ; i<n ; i++) sum += (long long)arr[i];

    long long ans = 0;
    for(int i=0 ; i<n ; i++){
        long long raze = min((long long)arr[i], sum/(n-i));
        ans += raze*raze;
        sum -= raze;
    }
    printf("%lld\n",ans);
}
