#include <cstdio>

int main(){
    int n;
    int ans = 0;
    scanf("%d",&n);
    while(n--){
        char str[101];
        int checked[27] = {0,};
        scanf("%s",str);
        char s = str[0];
        bool flag = true;
        checked[s-'a']++;
        for(int i=1 ; str[i] != 0 ; i++){
            if(checked[str[i]-'a'] != -1){
                if(str[i] == s){
                    checked[str[i]-'a']++;
                }else{
                    checked[s - 'a'] = -1;
                    s = str[i];
                }
            }else{
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    printf("%d\n",ans);
}
