#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long a,b,c;
long long multi(long long n, long long cnt){
    if(cnt == 0) return 1;

    long long temp = multi(n, cnt/2);
    long long res = (temp*temp)%c;
    if(cnt%2) res = (res*n)%c;
    return res;
}
int main(){
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld\n",multi(a, b));
}
