#include <cstdio>

using namespace std;

int bt[11][512];
int arr[1200];
int dIdx[11] = {0,};
int pow(int a, int b){
    int ret = 1;
    while(b>0){
        if(b&1) ret *=a;
        a*=a;
        b=b>>1;
    }
    return ret;
}

void tree(int s, int e, int d){
    if(e-s<0) return;

    int mid = (s+e)/2;
    bt[d][dIdx[d]++] = arr[mid];
    tree(s, mid-1, d+1);
    tree(mid+1, e, d+1);
}
int main(){
    int k;

    scanf("%d",&k);
    for(int i=0 ; i<pow(2,k)-1 ; i++){
        scanf("%d",&arr[i]);
    }
    tree(0,pow(2,k)-1,0);
    for(int i=0 ; i<k ; i++){
        for(int j=0 ; j<pow(2,i) ; j++){
            printf("%d ",bt[i][j]);
        }
        printf("\n");
    }
}
