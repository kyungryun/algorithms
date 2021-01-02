#include <cstdio>
#include <vector>
using namespace std;

int arr[10001];
int d[10001];
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    int len = 1;
    int now = arr[0];
    int flag = 1;
    int newIdx = 0;
    int ans = 0;
    if(len >= l){
        ans++;
        d[0] = 1;
    }
    for(int i=1 ; i<n ; i++){
        if(now < arr[i] && flag){
            now = arr[i];
            len++;
        }else if(now < arr[i] && !flag){
            if(arr[i-2] < arr[i]){
                now = arr[i];
                len++;
            }else{
                now = arr[newIdx];
                len = 1;
                flag = 1;
                i = newIdx;
            }
        }else{
            if(flag){
                now = arr[i];
                newIdx = i;
                len++;
                flag = 0;
            }else{
                now = arr[newIdx];
                i = newIdx;
                len = 1;
                flag = 1;
            }
        }
        if(len >= l){
            if(d[i] == 0) ans += (len-l+1);
            d[i] = 1;
        }
    }
    printf("%d\n",ans);
}
