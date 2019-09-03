#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=n ; i>0 ; i--){
        for(int j=0 ; j<n-i ; j++) printf(" ");
        for(int j=i*2-1 ; j>0 ; j--){
            printf("*");
        }
        printf("\n");
    }
}
