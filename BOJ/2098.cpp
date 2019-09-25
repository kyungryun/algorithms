#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n;
int city[17][17];
int dp[17][1<<16];
int ans;
int tsp(int cur, int visited){
    if(visited == (1<<n)-1){
        if(city[cur][0] == 0) return INF;
        else return city[cur][0];
    }

    int &res = dp[cur][visited];
    if(res != -1) return res;

    res = INF;
    for(int i=0 ; i<n ; i++){
        if(visited & (1<<i) || city[cur][i] == 0) continue;

        res = min(res, tsp(i, visited | (1<<i)) + city[cur][i]);
    }
    return res;
}
int main(){
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&city[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",tsp(0,1));
}
