#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int R,C;
int dr[4] = {0,0,1,-1};
int dc[4]  ={1,-1,0,0};
char map[1502][1502];
int sr,sc,er,ec;
int day;
queue<pair<int, int>> wq,nwq;
queue<pair<int, int>> sq,nsq;
bool visited[1501][1501];
void ice(){
    while(!wq.empty()){
        int r = wq.front().first;
        int c = wq.front().second;
        wq.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >=0 && nr < R && nc >= 0 && nc < C){
                if(map[nr][nc] == 'X'){
                    map[nr][nc] = '.';
                    nwq.push(make_pair(nr,nc));
                }
            }
        }
    }
}
bool swan(){
    while(!sq.empty()){
        int r = sq.front().first;
        int c = sq.front().second;
        sq.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C){
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    if(nr == er && nc == ec){
                        return true;
                    }
                    else if(map[nr][nc] == '.'){
                        sq.push(make_pair(nr,nc));
                    }
                    else if(map[nr][nc] == 'X'){
                        nsq.push(make_pair(nr,nc));
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&R,&C);
    for(int i=0 ; i<R ; i++){
        scanf("%s",map[i]);
    }
    int flag = true;
    for(int i=0 ; i<R ; i++){
        for(int j=0 ; j<C ; j++){
            if(map[i][j] == 'L' && flag){
                sr = i;
                sc = j;
                map[i][j] = '.';
                flag = false;
            }else if(map[i][j] == 'L' && !flag){
                er = i;
                ec = j;
                map[i][j] = '.';
            }
            if(map[i][j] == '.') wq.push(make_pair(i,j));
        }
    }
    visited[sr][sc] = true;
    sq.push(make_pair(sr,sc));
    day = 0;
    while(1){
        if(swan()){
            break;
        }else{
            ice();
            wq = nwq;
            sq = nsq;
            while(!nwq.empty())nwq.pop();
            while(!nsq.empty())nsq.pop();
            day++;
        }
    }
    printf("%d\n",day);
}
