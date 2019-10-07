#include <cstdio>

using namespace std;


int n;
int arr[1001];
int main(){
    scanf("%d",&n);
    int MAX = 0;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
        if(arr[i] > MAX) MAX = arr[i];
    }
    double ans = 0;
    for(int i=0 ; i<n ; i++){
        ans += ((double)arr[i]/MAX)*100;
    }
    printf("%lf\n",(double)ans/n);
}
