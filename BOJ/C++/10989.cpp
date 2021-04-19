#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[10001];
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        int nu;
        scanf("%d",&nu);
        arr[nu]++;
    }
    int cnt = 1;
    for(int i=1 ; i<10001 ; i++){
        for(int j=0 ; j<arr[i] ; j++){
            printf("%d\n",cnt);
        }
        cnt++;
    }
}
