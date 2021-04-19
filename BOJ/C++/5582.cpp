#include <cstdio>

int main(){
    int ans = 0;
    char a[4001];
    char b[4001];
    int d[4001][4001] = {0,};
    scanf("%s",a);
    scanf("%s",b);
    for(int i=0 ; a[i] != 0 ; i++){
        for(int j=0 ; b[j] != 0 ; j++){
            if(a[i] == b[j]){
                if(i==0 || j==0) d[i][j] = 1;
                else d[i][j] = d[i-1][j-1] + 1;

                if(ans < d[i][j]) ans = d[i][j];
            }
        }
    }
    printf("%d\n",ans);
}
