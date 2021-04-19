#include <cstdio>
int n;
char map[301][8];

int check(int a, int b){
    int cnt = 0;
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<7 ; j++){
            if(map[a+i][j] != map[b+i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n*5 ; i++){
        scanf("%s",map[i]);
    }
    int ans = 40;
    int art = 0;
    for(int i=0 ; i<5*n ; i+=5){
        for(int j=i+5 ; j<5*n ; j+=5){
            int temp = check(i,j);
            if(ans > temp) {
                ans = temp;
            }
        }
    }
    int arr[51] = {0,};
    int idx = 0;
    for(int i=0 ; i<5*n ; i+=5){
        for(int j=i+5 ; j<5*n ; j+=5){
            if(check(i,j) == ans){
                arr[i/5] = 1;
                arr[j/5] = 1;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(arr[i]) printf("%d ",i+1);
    }
    printf("\n");
}
