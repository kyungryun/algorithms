#include <cstdio>
using namespace std;


int main(){
    int T;
    int n;
    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        scanf("%d",&n);

        printf("#%d ",t);
        for(int i=0 ; i<n ; i++){
            printf("1/%d ",n);
        }
        printf("\n");
    }
}
