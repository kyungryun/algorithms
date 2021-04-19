#include <cstdio>

using namespace std;

bool room[101];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);

        for(int i=0 ; i<=n ; i++) room[i] = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=i ; j<=n ; j+=i){
                room[j] = !room[j];
            }
        }
        int ans = 0;
        for(int i=1 ; i<=n  ;i++) ans += room[i];

        printf("%d\n",ans);
    }
}