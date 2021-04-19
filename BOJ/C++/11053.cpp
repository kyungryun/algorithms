#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int a[1001]={0,};
    int dp[1001]={0,};
    int n,max=0;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++) scanf("%d",&a[i]);
    for(int i=1 ; i<=n ; i++){
        int min = 0;
        for(int j=0 ; j<i ; j++){
            if(a[i] > a[j] && min < dp[j]) min = dp[j];
        }
        dp[i] = min+1;
        if(max < dp[i]) max = dp[i];
    }
	printf("%d\n",max);

}