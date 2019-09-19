#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int e,s,m;
int main(){
    scanf("%d%d%d",&e,&s,&m);
    int E=1,S=1,M=1;

    int year = 1;
    while(1){
        if(e == E && s == S && m == M) break;
        E = E+1 > 15 ? 1 : E+1;
        S = S+1 > 28 ? 1 : S+1;
        M = M+1 > 19 ? 1 : M+1;
        year++;
    }
    printf("%d\n",year);
}
