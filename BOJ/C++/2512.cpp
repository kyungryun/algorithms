#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int budget[10001];
int MAX;
int ans;
int main(){
    scanf("%d",&n);
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&budget[i]);
        MAX = max(MAX, budget[i]);
        sum += budget[i];
    }
    scanf("%d",&m);


    if(sum <= m){
        ans = MAX;
    }else{
        int left = 0;
        int right = MAX;
        while(left <= right){
            sum = 0;
            int mid = (left + right)/2;
            for(int i=0 ; i<n ; i++){
                if(budget[i] <= mid) sum += budget[i];
                else sum += mid;
            }
            if(sum == m){
                ans = mid;
                break;
            }
            else if(sum > m){
                right = mid-1;
            }else{
                left = mid+1;
                ans = max(ans, mid);
            }
        }

    }
    printf("%d\n",ans);
}
