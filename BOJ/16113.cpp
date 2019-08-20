#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char signal;
char decode[5][20005];
int n;
char number[10][16]={{"####.##.##.####"},{".#..#..#..#..#."},
                    {"###..#####..###"},{"###..####..####"},
                    {"#.##.####..#..#"},{"####..###..####"},
                    {"####..####.####"},{"###..#..#..#..#"},
                    {"####.#####.####"},{"####.####..####"}};

int check(int c){
    for(int i=0 ; i<10 ; i++){
        if(i == 1) continue;
        int cnt = 0;
        bool flag = true;
        for(int j=0 ; j<5 ; j++){
            for(int k=0 ; k<3 ; k++){
                if(decode[j][c+k] != number[i][cnt++]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) return i;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<n/5 ; j++){
            scanf(" %c",&signal);
            decode[i][j] = signal;
        }
    }
    int i=0;
    while(i<n/5){
        if(decode[0][i] == '#'){
            int num = check(i);
            if(num == 1) i++;
            else i+=3;
            printf("%d",num);
        }else i++;
    }
    printf("\n");

}
