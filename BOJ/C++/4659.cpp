#include <cstdio>

int ztrcmp(char *a, char *b){
    int i=-1;
    while(a[++i]){
        if(a[i] != b[i]) break;
    }
    return a[i]-b[i];
}
int main(){
    while(1){
        char str[21];
        scanf("%s",str);
        if(ztrcmp(str,"end") == 0) break;
        int za = 0, mo = 0;
        bool flag = true;
        bool zF = false;
        for(int i=0 ; str[i] != 0 ; i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                if(str[i] == str[i+1]){
                    if(str[i] == 'e' || str[i] == 'o'){
                        za++;
                        mo = 0;
                        zF = true;
                    }else{
                        flag = false;
                        break;
                    }
                }else{
                    za++;
                    mo = 0;
                    zF = true;
                }

            }else{
                if(str[i] == str[i+1]){
                    flag = false;
                    break;
                }
                za = 0;
                mo++;
            }
            if(za==3 || mo == 3){
                flag = false;
                break;
            }
        }

        if(flag && zF) printf("<%s> is acceptable.\n", str);
        else printf("<%s> is not acceptable.\n", str);
    }
}
