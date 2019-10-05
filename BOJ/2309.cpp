#include <cstdio>
#include <algorithm>
using namespace std;

bool visited[9];
int sum;
int a[7];
bool flag = true;
void dfs(int cnt, int *arr, int idx){
    if(!flag) return;
    if(cnt == 7){
        int sum = 0;
        for(int i=0 ; i<9 ; i++){
            if(visited[i]) sum += arr[i];
        }
        if(sum == 100){
            int j = 0;
            for(int i=0 ; i<9 ; i++){
                if(visited[i]) a[j++] = arr[i];
            }
            flag = false;
        }
        return;
    }

    for(int i=idx ; i<9 ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(cnt+1, arr,i);
        visited[i] = false;
    }
}
int main(){
    int arr[9];
    for(int i=0 ; i<9 ; i++) scanf("%d",&arr[i]);
    dfs(0,arr,0);
    sort(a,a+7);
    for(int i=0 ; i<7 ; i++) printf("%d\n",a[i]);
}
