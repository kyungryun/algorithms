#include <cstdio>

using namespace std;

int d[1001];
int square(int n){
    if(n <= 1){
        return 1;
    }else if(n == 2){
        return 3;
    }
    if(d[n] != 0) return d[n];
    else{
        d[n] = (square(n-1) + square(n-2)*2)%10007;
        return d[n];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",square(n));
}
