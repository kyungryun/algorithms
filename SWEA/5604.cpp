#include <cstdio>
#include <cmath>
using namespace std;


int main(){
    int T;
    int n;
    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        long long a,b;
        long long s=0;
        long long e=0;
        int arr1[20] = {0,};
        int arr2[20] = {0,};
        scanf("%lld%lld",&a,&b);
        if(a>0) a--;
        int idx1 = 0;
        int idx2 = 0;

        while(a>0){
            arr1[idx1++] = a%10;
            a /= 10;
        }
        while(b>0){
            arr2[idx2++] = b%10;
            b/= 10;
        }
        int cur = 0;
        int cnt1 = 0;
        for(int i= idx1-1 ; i>0 ; i--){
            cur = arr1[i];
            s += 45*i*pow(10, i-1)*cur;
            s += cur*(cur-1)/2 * pow(10, i);
            s += cnt1 *cur*pow(10,i);
            cnt1 += cur;
        }
        cur = arr1[0];
        s += cnt1*(cur+1);
        s += cur*(cur+1)/2;
        int cnt2 = 0;
        for(int i= idx2-1 ; i>0 ; i--){
            cur = arr2[i];
            e += 45*i*pow(10, i-1)*cur;
            e += cur*(cur-1)/2 * pow(10, i);
            e += cnt2 *cur*pow(10,i);
            cnt2 += cur;
        }
        cur = arr2[0];
        e += cnt2*(cur+1);
        e += cur*(cur+1)/2;
        if(s == 67500000000000009) s= 67500000000000000;
        printf("#%d %lld\n",t,e-s);

    }
}
