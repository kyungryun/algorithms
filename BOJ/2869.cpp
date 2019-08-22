#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a,b,v;
int ans;
int main(){
    scanf("%d%d%d",&a,&b,&v);

    int left = 0;
    int right = v/(a-b) + 1;
    int ans = 1e9;
    while(left <= right){
        int mid = (left + right) / 2;

        if(v <= mid*(a-b) + a){
            right = mid-1;
            ans = min(ans, mid+1);
        }else left = mid+1;
    }
    printf("%d\n",ans);
}
