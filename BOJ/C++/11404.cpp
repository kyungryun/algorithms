#include <cstdio>

const int INF = 987654321;
int main(){
    int n,m;
    int arr[101][101];
    int a,b,c;

    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            arr[i][j] = i==j ? 0 : INF;
        }
    }
    for(int i=0 ; i<m ; i++){
        scanf("%d%d%d",&a,&b,&c);
        arr[a][b] = arr[a][b] > c ? c : arr[a][b];
    }

    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            printf("%d ",arr[i][j] == INF ? 0 : arr[i][j]);
        }
        printf("\n");
    }
}
