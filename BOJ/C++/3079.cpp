
#include <cstdio>
#include <algorithm>
using namespace std;

long long n,m;
long long t[100001];
long long ans;
int main(){
    scanf("%lld%lld",&n,&m);
    long long MAX = 0;
    for(int i=0 ; i<n ; i++) {
        scanf("%lld",&t[i]);
        MAX = max(MAX, t[i]);
    }

    long long left = 0;
    long long right = MAX*m;
    ans = right;
    while(left <= right){
        long long mid = (left + right)/2;
        long long people = 0;
        for(int i=0 ; i<n ; i++){
            people += mid / t[i];
        }
        if(people < m) left = mid+1;
        else{
            if(ans > mid) ans = mid;
            right = mid-1;
        }
    }

    printf("%lld\n",ans);
}
