#include <cstdio>

int arr[21];

void swap(int s, int e){
    int buf[21];
    int idx = 0;
    for(int i=s ; i<=e ; i++) buf[idx++] = arr[i];
    idx = 0;
    for(int i=e ; i>=s ; i--) arr[i] = buf[idx++];
}
int main(){
    for(int i=1 ; i<=20 ; i++) arr[i] = i;
    int a,b;
    for(int t=0 ; t<10 ; t++){
        scanf("%d%d",&a,&b);
        swap(a,b);
    }
    for(int i=1 ; i<=20 ; i++) printf("%d ",arr[i]);
    printf("\n");
}
