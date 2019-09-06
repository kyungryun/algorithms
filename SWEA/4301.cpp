#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int ans;
int n,m;
int map[1003][1003];

int main(){
    int T;

    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(map[i][j] == 0){
                    map[i+2][j] = 1;
                    map[i][j+2] = 1;
                }
            }

        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(map[i][j] == 0) ans++;
            }
        }
        printf("#%d %d\n",t,ans);
    }
}
