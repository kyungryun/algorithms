#include <cstdio>

using namespace std;

int n,m,r;
int arr[301][301];
int rotate(int k){
    for(int i=0 ; i<k ; i++){
        int temp = arr[i][i];
        for(int j=i+1 ; j<m-i ; j++) arr[i][j-1] = arr[i][j];
        for(int j=i+1 ; j<n-i ; j++) arr[j-1][m-i-1] = arr[j][m-i-1];
        for(int j=m-i-2 ; j>=i ; j--) arr[n-i-1][j+1] = arr[n-i-1][j];
        for(int j=n-i-2 ; j>=i ; j--) arr[j+1][i] = arr[j][i];
        arr[i+1][i] = temp;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&r);
    int k;
    if(n<m) k = n/2;
    else k = m/2;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0 ; i<r ; i++) rotate(k);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
