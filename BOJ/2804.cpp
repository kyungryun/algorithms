#include <cstdio>

char A[31];
char B[31];
char map[31][31];
int ar[27];
int br[27];
int main(){
    scanf("%s %s",A,B);
    int aSize = 0, bSize = 0;
    for(int i=0 ; A[i] != 0 ; i++){
        aSize++;
    }
    for(int i=0 ; B[i] != 0 ; i++){
        bSize++;
    }
    bool flag = false;
    int i,j;
    for(i=0 ; i<aSize ; i++){
        for(j=0 ; j<bSize ; j++){
            if(A[i] == B[j]){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    for(int b=0 ; b<bSize ; b++){
        for(int a=0 ; a<aSize ; a++){
            map[b][a] = '.';
        }
    }
    for(int b=0 ; b<bSize ; b++) map[b][i] = B[b];
    for(int a=0 ; a<aSize ; a++) map[j][a] = A[a];

    for(int b=0 ; b<bSize ; b++){
        for(int a=0 ; a<aSize ; a++){
            printf("%c",map[b][a]);
        }
        printf("\n");
    }

}
