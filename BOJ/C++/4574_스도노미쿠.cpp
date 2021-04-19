// 스도노미쿠
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[11][11];
bool row[11][11];
bool col[11][11];
bool square[11][11];
bool domino[11][11];
int dr[2] = {0,1};
int dc[2] = {1,0};
bool flag;
int tc = 1;
void init(){
    memset(map,0,sizeof(map));
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    memset(square,false,sizeof(square));
    memset(domino,false,sizeof(domino));
    flag = false;
}
void print(){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
}
int mat(int r, int c){
    return (r/3)*3 + (c/3);
}
bool check(int r, int c, int num){
    return (!row[r][num] && !col[c][num] && !square[mat(r,c)][num]);
}
void dfs(int idx){
    if(flag) return;
    if(idx == 81){
        print();
        flag = true;
        return;
    }
    int r = idx/9;
    int c = idx%9;
    if(map[r][c] != 0) dfs(idx+1);
    else{
        for(int d=0 ; d<2 ; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= 9 || nc < 0 || nc >= 9) continue;
            if(map[nr][nc] != 0) continue;

            for(int i=1 ; i<10 ; i++){
                for(int j=1 ; j<10 ; j++){
                    if(i==j) continue;
                    if(domino[i][j]) continue;
                    if(check(r,c,i) && check(nr,nc,j)){
                        map[r][c] = i;
                        map[nr][nc] = j;
                        row[r][i] = col[c][i] = square[mat(r,c)][i] = true;
                        row[nr][j] = col[nc][j] = square[mat(nr,nc)][j] = true;
                        domino[i][j] = domino[j][i] = true;
                        dfs(idx+1);
                        map[r][c] = 0;
                        map[nr][nc] = 0;
                        row[r][i] = col[c][i] = square[mat(r,c)][i] = false;
                        row[nr][j] = col[nc][j] = square[mat(nr,nc)][j] = false;
                        domino[i][j] = domino[j][i] = false;
                    }
                }
            }
        }
    }
}
int main(){
    while(1){
        int num,num2;
        char index[2][3];
        scanf("%d",&n);
        if(n == 0) break;
        memset(domino,0,sizeof(domino));
        for(int i=0 ; i<n ; i++){
            scanf("%d%s%d%s",&num,index[0],&num2,index[1]);
            int r1 = index[0][0]-'A';
            int c1 = index[0][1]-'1';
            int r2 = index[1][0]-'A';
            int c2 = index[1][1]-'1';
            map[r1][c1] = num;
            map[r2][c2] = num2;
            domino[num][num2] = domino[num2][num] = true;
            row[r1][num] = true;
            row[r2][num2] = true;
            col[c1][num] = true;
            col[c2][num2] = true;
            square[mat(r1,c1)][num] = true;
            square[mat(r2,c2)][num2] = true;
        }
        //print();
        for(int i=1 ; i<10 ; i++){
            scanf("%s",index[0]);
            map[index[0][0]-'A'][index[0][1]-'1'] = i;
            row[index[0][0]-'A'][i] = true;
            col[index[0][1]-'1'][i] = true;
            square[mat(index[0][0]-'A',index[0][1]-'1')][i] = true;
        }
        printf("Puzzle %d\n",tc++);
        dfs(0);

        init();
    }

}
