#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Room{
    long long t;
    long long a;
    long long h;
}room[123458];
int main(){
    long long n,atk;
    scanf("%lld%lld",&n,&atk);

    for(int i=0 ; i<n ; i++){
        scanf("%lld%lld%lld",&room[i].t,&room[i].a,&room[i].h);
    }

    long long left = 0;
    long long right = 1e18;
    long long ans;
    while(left <= right){
        long long mid = (left + right)/2;
        long long hp = mid;
        long long tatk = atk;
        for(int i=0 ; i<n ; i++){
            if(room[i].t == 1){
                long long stat = room[i].h % tatk;
                if(stat == 0) hp -= (room[i].h/tatk-1)*room[i].a;
                else hp -= (room[i].h/tatk)*room[i].a;
            }else{
                tatk += room[i].a;
                hp = min(mid, hp+room[i].h);
            }
            if(hp <= 0) break;
        }
        if(hp >0){
            ans = mid;
            right = mid-1;
        }else left = mid+1;
    }
    printf("%lld\n",ans);
}
