#include <cstdio>

int n;
int main(){
    scanf("%d",&n);
    if(n<100) printf("%d\n",n);
    else{
        int cnt = 99;
        for(int i=100 ; i<=n ; i++){
            int a,b,c;
            a = i/100;
            b = i%100/10;
            c = i%10;
            if(b-a == c-b) cnt++;
        }
        printf("%d\n",cnt);
    }
}
