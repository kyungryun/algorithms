#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[51][10];
int bat[10];
int ans;
int main(){
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=9 ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int tmp[8];
    bat[4] = 1;
    int idx = 0;
    for(int i=2 ; i<=9 ; i++) {
        tmp[idx++] = i;
    }
    do{
        idx = 1;
        for(int i=0 ; i<8 ; i++){
            if(idx == 4) idx++;
            bat[idx++] = tmp[i];
        }
        int out = 0;
        int inning = 1;
        int field[3];
        int i=1;
        int score = 0;
        while(inning != n+1){
            for(int i=0 ; i<3 ; i++) field[i] = 0;
            while(out < 3){
                if(arr[inning][bat[i]] == 0){
                    out++;
                }else if(arr[inning][bat[i]] == 1){
                    if(field[2]){
                        score++;
                        field[2] = 0;
                    }

                    field[2] = field[1];
                    field[1] = field[0];
                    field[0] = 1;
                }else if(arr[inning][bat[i]] == 2){
                    for(int i=2 ; i>=1 ; i--){
                        if(field[i]){
                            score++;
                            field[i] = 0;
                        }
                    }
                    field[2] = field[0];
                    field[1] = 1;
                    field[0] = 0;
                }else if(arr[inning][bat[i]] == 3){
                    for(int i=0 ; i<3 ; i++){
                        if(field[i]) score++;
                        field[i] = 0;
                    }
                    field[2] = 1;
                }else if(arr[inning][bat[i]] == 4){
                    for(int i=0 ; i<3 ; i++){
                        if(field[i]) score++;
                        field[i] = 0;
                    }
                    score++;
                }

                if(i+1 == 10) i = 1;
                else i++;
            }
            inning++;
            out = 0;
        }
        ans = max(ans, score);
    }while(next_permutation(tmp, tmp+8));
    printf("%d\n",ans);
}
