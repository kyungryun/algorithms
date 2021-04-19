#include <cstdio>

int main(){
    int t = 3;
    while(t--){
        int c=0;
        int n;
        for(int i=0 ; i<4 ; i++){
            scanf("%d",&n);
            if(n == 0) c++;
        }
        if(c == 0) printf("E\n");
        else if(c==1) printf("A\n");
        else if(c==2) printf("B\n");
        else if(c==3) printf("C\n");
        else printf("D\n");
    }
}
