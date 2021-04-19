#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n,atk;
    scanf("%lld%lld",&n,&atk);
    long long t,a,h;
    long long maxHP = 0;
    long long nowHP = 0;
    for(int i=0 ; i<n ; i++){
        scanf("%lld%lld%lld",&t,&a,&h);
        if(t == 1){
            nowHP -= ((h-1)/atk)*a;
        }else{
            atk += a;
            if(nowHP + h > 0) nowHP = 0;
            else nowHP += h;

        }
        maxHP = min(maxHP, nowHP);
    }
    printf("%lld\n",1-maxHP);
}
