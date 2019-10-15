#include <cstdio>

int ztrlen(char *str){
    int cnt = 0;
    while(*str++)cnt++;
    return cnt;
}
int main(){
    int n;
    char str[51];
    char ans[51];
    scanf("%d",&n);
    scanf("%s",ans);
    for(int i=1 ; i<n ; i++){
        scanf("%s",str);
        for(int j=0 ; j<ztrlen(str) ; j++){
            if(ans[j] != str[j]) ans[j] = '?';
        }
    }
    printf("%s\n",ans);
}
