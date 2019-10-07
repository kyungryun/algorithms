#include <cstdio>

using namespace std;

int main(){
    int c;
    scanf("%d",&c);
    while(c--){
        int n;
        int arr[1001];
        scanf("%d",&n);
        double ave = 0;
        for(int i=0 ; i<n ; i++){
            scanf("%d",&arr[i]);
            ave += arr[i];
        }
        ave/=n;
        int cnt = 0;
        for(int i=0 ; i<n ;i++){
            if(arr[i] > ave) cnt++;
        }
        printf("%.3lf%\n",(double)cnt/n * 100);

    }
}
