#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[101];
int b[101];
bool compare(int a, int b){
    return a > b;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0 ; i<n ; i++){
        scanf("%d",&b[i]);
    }
    int ans = 0;
    sort(a, a+n);
    sort(b, b+n, compare);
    for(int i=0 ; i<n ; i++){
        ans += a[i]*b[i];
    }
    printf("%d\n",ans);
}
