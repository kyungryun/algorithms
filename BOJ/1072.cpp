#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long x,y;
long long ans;

int main(){
    scanf("%lld%lld",&x,&y);

    long long left = 0;
    long long right = x;
    int z = (100*y/x);

    if(z >= 99) ans = -1;
    else{
        while(left <= right){
            long long mid = (left + right)/2;
            long long now = 100*(y+mid)/(x+mid);
            if(z < now) right = mid-1;
            else{
                ans = mid+1;
                left = mid + 1;
             }
        }
    }
    printf("%lld\n",ans);

}
