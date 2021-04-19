#include <cstdio>
#include <algorithm>
#define swap(a,b) a^=b^=a^=b;
using namespace std;


int m;

int arr[4];
int main(){
    scanf("%d",&m);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    int a,b;
    for(int i=0 ; i<m ; i++){
        scanf("%d%d",&a,&b);
        swap(arr[a],arr[b]);
    }
    for(int i=1 ; i<=3 ; i++){
        if(arr[i] == 1) printf("%d\n",i);
    }


}
