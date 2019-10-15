#include <cstdio>
#include <algorithm>

using namespace std;
int ztrlen(char *a){
    int cnt;
    while(*a++)cnt++;

    return cnt;
}
int main(){
    char a[1002]="0";
    char b[1002]="0";
    int d[1002][1002] = {0,};
    scanf("%s%s",a+1,b+1);
    for(int i=1 ; a[i] != 0 ; i++){
        for(int j=1 ; b[j] != 0 ;j++){
            if(a[i] == b[j]){
                d[i][j] = d[i-1][j-1] + 1;
            }else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    printf("%d\n",d[ztrlen(a)-1][ztrlen(b)-1]);
}
