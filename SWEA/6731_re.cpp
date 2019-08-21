#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int T;
    int n;
    scanf("%d",&T);
    for(int t = 1 ; t<=T ; t++){
        char board[1001][1001];
        memset(board, 'W',sizeof(board));
        int r[1001]={0,};
        int c[1001]={0,};
        scanf("%d",&n);

        for(int i=0 ; i<n ; i++){
            char t[1001];
            scanf("%s",t);
            for(int j=0 ; j<n ; j++){
                if(t[j] == 'B'){
                    r[i]++;
                    c[j]++;
                    board[i][j] = 'B';
                }
            }
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                int b = r[i] + c[j];
                if(board[i][j] == 'B') b--;
                if(b%2) ans++;
            }
        }
        printf("#%d %d\n",t, ans);
    }
}
