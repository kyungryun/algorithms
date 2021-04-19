#include <cstdio>
#include <vector>
using namespace std;

int map[9][9];
bool row[10][10];
bool col[10][10];
bool square[10][10];
int cnt = 0;
int flag;
int resize(int r, int c){
    return (r/3)*3 + c/3;
}
void print(){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
void dfs(int idx){
    if(flag) return;
    if(idx == 81){
        flag = true;
        print();
        return;
    }
    int r = idx/9;
    int c = idx%9;
    if(map[r][c] == 0){
        for(int i=1 ; i<=9 ; i++){
            if(!row[r][i] && !col[c][i] && !square[resize(r,c)][i]){
                row[r][i] = true;
                col[c][i] = true;
                square[resize(r,c)][i] = true;
                map[r][c] = i;
                dfs(idx+1);
                row[r][i] = false;
                col[c][i] = false;
                square[resize(r,c)][i] = false;
                map[r][c] = 0;
            }
        }
    }else dfs(idx+1);

}
int main(){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] != 0){
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[resize(i,j)][map[i][j]] = true;
            }
        }
    }
    dfs(0);
}
