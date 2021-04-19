#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        int ans = 0;
        for(int i=n ; i<=m ; i++){
            int arr[10]={0,};
            int num = i;
            bool flag = true;
            while(num){
                arr[num%10]++;
                num/=10;
            }
            for(int i=0 ; i<10 ; i++){
                if(arr[i] > 1){
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        printf("%d\n",ans);
    }
}
