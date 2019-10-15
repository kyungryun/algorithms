#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int r,g,b;
    int d[1001][3] = {0,};
    int home[1001][3];
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<3 ; j++){
            scanf("%d",&home[i][j]);
        }
    }
    for(int i=0 ; i<3 ; i++){
        d[0][i] = 0;
    }
    for(int i=1 ; i<=n; i++){
        d[i][0] = min(d[i-1][1],d[i-1][2]) + home[i][0];
        d[i][1] = min(d[i-1][0],d[i-1][2]) + home[i][1];
        d[i][2] = min(d[i-1][1],d[i-1][0]) + home[i][2];
    }
    printf("%d\n",min(d[n][0],min(d[n][1],d[n][2])));
}
