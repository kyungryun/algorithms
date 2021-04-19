#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[10001];

int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    if(prev_permutation(arr, arr+n)){
        for(int i=0 ; i<n ; i++) printf("%d ",arr[i]);
        printf("\n");
    }else printf("-1\n");
}
