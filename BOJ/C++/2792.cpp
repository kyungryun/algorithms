#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int arr[300002];
    int n,m;
    int left = 0;
    int right = 0;
    int total = 0;
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<m ; i++){
        scanf("%d",&arr[i]);
        total += arr[i];
        right = max(right, arr[i]);
    }
    int ans = 987654321;
    while(left <= right){
        int mid = (left + right) / 2;
        int people = 0;
        for(int i=0 ; i<m ; i++){
            int div = arr[i]/mid;
            if(arr[i]%mid == 0){
                people += div;
            }else{
                people += (div + 1);
            }
        }
        if(people > n) left = mid+1;
        else{
            right = mid - 1;
            ans = min(ans, mid);
        }
    }
    printf("%d\n",ans);
}
