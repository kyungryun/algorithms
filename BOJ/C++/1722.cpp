#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
long long k;
int arr[21];
long long f[21];
bool chk[21];
int main(){
    scanf("%d%d",&n,&m);
    if(m == 1) scanf("%lld",&k);
    else{
        for(int i=0 ; i<n ; i++) scanf("%d",&arr[i]);
    }
    f[0] = 1;
    for(int i=1 ; i<=20 ; i++) f[i] = f[i-1]*i;
    if(m == 2){
        long long ans = 1;
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<arr[i] ; j++){
                if(!chk[j]) ans += f[n-i-1];
            }
            chk[arr[i]] = true;
        }
        printf("%lld\n",ans);
    }else{
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(chk[j]) continue;
                if(f[n-i-1] < k) k -= f[n-i-1];
                else{
                    arr[i] = j;
                    chk[j] = true;
                    break;
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
