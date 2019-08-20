#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R,C;
int dr[4] = {0,0,1,-1};
int dc[4]  ={1,-1,0,0};
char map[1501][1501];
int sr,sc,er,ec;
int day=0;
void ice(){
    queue<pair<int, int>> q;
    day++;
    for(int i=0 ; i<R ; i++){
        for(int j=0 ; j<C ; j++){
            if(map[i][j] == 'X') q.push(make_pair(i,j));
        }
    }
    vector<pair<int, int>> v;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >=R || nc < 0 || nc >= C || map[nr][nc] == 'X') continue;
            if(map[nr][nc] == '.'){
                v.push_back(make_pair(r,c));
                break;
            }
        }
    }
    for(int i=0 ; i<v.size() ; i++){
        map[v[i].first][v[i].second] = '.';
    }
}
bool swan(){
    queue<pair<int, int>> q;
    q.push(make_pair(sr,sc));
    bool visited[1501][1501] = {false,};
    visited[sr][sc] = true;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(r == er && c == ec){
            return true;
        }
        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
            if(map[nr][nc] =='.'){
                visited[nr][nc] = true;
                q.push(make_pair(nr,nc));
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
                break;
            }
        }
    }
    while(!swan()){
        ice();
    }
    printf("%d\n",day);
}
