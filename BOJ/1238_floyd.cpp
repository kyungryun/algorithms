#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int main(){
    int n,m,x;
    int arr[1001][1001];
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    int u,v,w;
    for(int i=0 ; i<m ; i++){
        scanf("%d%d%d",&u,&v,&w);
        arr[u][v] = w;
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
    int ans = 0;
    for(int i=1 ; i<=n ; i++){
        ans = max(arr[i][x]+arr[x][i], ans);
    }
    printf("%d\n",ans);
}
