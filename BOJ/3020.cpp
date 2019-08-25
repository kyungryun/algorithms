#include <cstdio>
#include <algorithm>

using namespace std;

int a[500001];
int b[500001];
int top[500001];
int bot[500001];
int total[500001];
int main(){
    int n,h;
    scanf("%d%d",&n,&h);
    for(int i=0 ; i<n/2 ; i++){
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        a[aa]++;
        b[bb]++;
    }
    int ans = 987654321;
    int cnt = 1;

    for(int i=h ; i>=1 ; i--){
        bot[i] = a[i] + bot[i+1];
        top[i] = b[i] + top[i+1];
    }
    for(int i=1 ; i<=h ; i++){
        total[i] = bot[i] + top[h-i + 1];
        if(total[i] <= ans){
            if(total[i] == ans) cnt++;
            else{
                ans = total[i];
                cnt = 1;
            }
        }
    }
    printf("%d %d\n",ans, cnt);
}
