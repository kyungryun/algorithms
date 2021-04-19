#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int m;
long long n,left,t_time;
long long right = 60000000000;
int arr[10001];
int main(){
    scanf("%lld%d",&n,&m);
    for(int i=0 ; i<m ; i++){
        scanf("%d",&arr[i]);
    }

    long long lastRide = 0;
    long long time;
    while(left <= right){
        time = m;
        long long mid = (left+right)/2;
        for(int i=0 ; i<m ; i++){
            time += mid/(long long)arr[i];
        }
        if(time <n){
            left = mid+1;
            lastRide = time;
        }else{
            right = mid-1;
            t_time = mid;
        }
    }
    int ans;
    int ride = lastRide;
    for(int i=0 ; i<m ; i++){
        if(ride == n) break;

        if(t_time%arr[i] == 0) {
            ride++;
            ans = i+1;
        }

    }
    printf("%d\n",ans);
}
