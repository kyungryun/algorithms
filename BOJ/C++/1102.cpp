#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 987654321;

int n,p,cnt;
int on;
int plant[17][17];
int dp[1<<17];
int power(int on, int cnt){
    int &res = dp[on];
    if(res != -1) return res;
    if(cnt >= p) return res = 0;
    res = INF;

    for(int i=0 ; i<n ; i++){
        if(on & 1<<i){
            for(int j=0 ; j<n ; j++){
                if(!(on & (1<<j))) res = min(res, power(on | (1<<j), cnt+1) + plant[i][j]);
            }
        }
    }

    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&plant[i][j]);
        }
    }
    char str[17];
    scanf("%s",str);
    for(int i=0 ; str[i] != 0 ; i++){
        if(str[i] == 'Y') on |= 1<<i, cnt++;
    }
    scanf("%d",&p);
    memset(dp,-1,sizeof(dp));
    int ans = power(on,cnt);
    printf("%d\n",ans==INF ? -1 : ans);
}
