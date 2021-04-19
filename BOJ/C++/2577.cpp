#include <cstdio>

using namespace std;

int a,b,c;
int number[10];
int main(){
    scanf("%d%d%d",&a,&b,&c);
    long long sum = a*b*c;
    while(sum != 0){
        number[sum%10]++;
        sum/=10;
    }
    for(int i=0 ; i<10 ; i++) printf("%d\n",number[i]);
}
