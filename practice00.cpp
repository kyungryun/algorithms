#include <cstdio>

int power(int n, int exp){
    int i, result = 1;
    for(i=0 ; i<exp ; i++){
        result = result*n;
    }
    return result;
}

int main(){
    printf("%d\n",power(2,8));
}
