#include <cstdio>
using namespace std;


int main(){
    int T;
    int n;
    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        int a[10001];
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)scanf("%d",&a[i]);
        int sum = 0;
        for(int i=0 ; i<n ; i++) sum += a[i];
        sum /= n;
        int add = 0;
        for(int i=0 ; i<n ; i++){
            if(sum > a[i]){
                add += sum-a[i];
            }
        }
        printf("#%d %d\n",t,add);

    }
}
