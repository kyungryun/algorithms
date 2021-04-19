#include <cstdio>

int n,m;

int main(){
    while(1){
        char str[21];
        char tmp[21];
        scanf("%s%*c",str);
        if(str[0] == '#'){
            break;
        }
        int cnt = 0;
        int idx = 0;
        bool flag = true;
        for(int i=0 ; str[i] != 0 ; i++) cnt++;
        for(int i=0 ; str[i] != 0 ; i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u'){
                for(int j=0 ; str[j] != 0 ; j++){
                    printf("%c",str[idx%cnt]);
                    idx++;
                }
                printf("ay\n");
                flag = false;
                break;
            }else{
                idx++;
            }
        }
        if(flag) printf("%say\n",str);
    }
}
