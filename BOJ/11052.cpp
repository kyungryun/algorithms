#include <cstdio>
#include <algorithm>
using namespace std;
int p[10001];
int d[10001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++){
        scanf("%d",&p[i]);
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            d[i] = max(d[i],d[i-j] + p[j] );
        }
    }
    printf("%d\n",d[n]);
}
