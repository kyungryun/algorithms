#include <cstdio>

using namespace std;

int main(){
    char str[101];
    scanf("%s",str);
    int cnt = 0;
    for(int i=0 ; str[i] != 0 ; i++){
        if(str[i] == 'c' && (str[i+1] == '-' || str[i+1] == '=')) {
            cnt++;
            i++;
        }else if(str[i] == 'd' && (str[i+1] == '-' ||(str[i+1] == 'z' && str[i+2] == '='))){
            cnt++;
            if(str[i+1] == 'z' && str[i+2] == '=') i++;
            i++;
        }else if(str[i] == 'l' && str[i+1] == 'j'){
            i++;
            cnt++;
        }else if(str[i] == 'n' && str[i+1] == 'j'){
            cnt++;
            i++;
        }else if((str[i] == 's' || str[i] == 'z') && str[i+1] == '='){
            cnt++;
            i++;
        }
        else cnt++;

    }
    printf("%d\n",cnt);
}
