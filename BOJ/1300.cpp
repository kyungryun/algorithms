
#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;
int ans;
int main(){
    scanf("%d",&n);
    scanf("%d",&k);
    int left = 1;
    int right = k;
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0;
        for(int i=1 ; i<=n ; i++){
            cnt += min(mid/i, n);
        }
        if(cnt < k) left = mid+1;
        else{
            ans = mid;
            right = mid - 1;
        }
    }
    printf("%d\n",ans);
}
