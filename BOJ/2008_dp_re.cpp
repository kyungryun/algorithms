// dp 어려움 다시 풀어보기
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int a,b,x,y;
int d[501][501];
int br[501];
int main(){
    scanf("%d%d",&m,&n);
    scanf("%d%d%d%d",&a,&b,&x,&y);
    int price = 0;
    a--;
    b--;
    for(int i=1 ; i<=n ; i++){
        scanf("%d",&br[i]);
        br[i]--;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            d[i][j] = 1e9;
        }
    }

    for(int i=0 ; i<m ; i++){
        if(i == a) d[0][i] = 0;
        else d[0][i] = abs(a-i)*y;
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<m ; j++){
            for(int k=0 ; k<m ; k++){
                if(k==j && (br[i] == k || br[i]+1 == k)){
                    d[i][j] = min(d[i][j],d[i-1][k]+x);
                }else if((k<=br[i] && br[i] <= j-1) || (j<=br[i] && br[i] <= k-1)){
                    d[i][j] = min(d[i][j],d[i-1][k]+(abs(j-k)-1)*y);
                }else{
                    d[i][j] = min(d[i][j],d[i-1][k]+abs(j-k)*y);
                }
            }
        }
    }
    printf("%d\n",d[n][b]);
}
