#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int n,k,d,a,b,c;
int a_a[100001];
int b_b[100001];
int c_c[100001];

int main(){
    scanf("%d%d%d",&n,&k,&d);
    for(int i=0 ; i<k ; i++){
        scanf("%d%d%d",&a_a[i],&b_b[i],&c_c[i]);

    }

    int left = 0;
    int right = 1000001;
    int ans;
    while(left <= right){
        int mid = (left + right) / 2;
        long long now = 0;
        for(int i=0 ; i<k ; i++){
            if(a_a[i] <= mid) now += ((min(b_b[i],mid)-a_a[i])/c_c[i]) + 1;
        }
        if(now >= d){
            ans = mid;
            right = mid-1;
        }else left = mid+1;
    }
    printf("%d\n",ans);


}
