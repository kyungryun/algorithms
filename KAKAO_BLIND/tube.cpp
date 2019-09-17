#include <cstdio>
#include <vector>
using namespace std;

int n,m;
int key[21][21];
int lock[21][21];
int rotKey[4][21][21];
int locks;
int rot(){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            rotKey[0][i][j] = key[i][j];
            rotKey[1][i][j] = key[n-j-1][i];
            rotKey[2][i][j] = key[n-i-1][n-j-1];
            rotKey[3][i][j] = key[j][n-i-1];
        }
    }
}
bool find(){
    for(int i= -n ; i<m ; i++){
        for(int j= -n ; j<m ; j++){
            for(int k=0 ; k<4 ; k++){
                bool flag = true;
                int cnt = 0;
                for(int a=0 ; a<n ; a++){
                    for(int b=0 ; b<n ; b++){
                        if(a+i < 0 || b+j < 0 || a+i>=m || b+j >=m ) continue;
                        if(rotKey[k][a][b] == 1 && lock[a+i][b+j] == 0) cnt++;
                        else if(rotKey[k][a][b] == 1 && lock[a+i][b+j] == 1){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag && cnt == locks){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&key[i][j]);

        }
    }
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d",&lock[i][j]);
            if(lock[i][j] == 0) locks++;
        }
    }
    rot();
    printf("%d\n",find());
}
