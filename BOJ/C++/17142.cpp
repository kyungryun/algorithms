#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int map[51][51];
int tempMap[51][51];
int visited[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int, int>> v;
vector<pair<int, int>> sel;
int MIN = 987654321;
int MAX = 0;

bool check(){
    int cnt = 0;
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(tempMap[i][j] == 0){
                cnt++;
            }
        }
    }
    if(cnt > M) return false;
    else return true;
}
void bfs(){
    queue<pair<int, pair<int, int> > > q;
    for(int i=0 ; i<M ; i++) q.push(make_pair(0,sel[i]));
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int time = q.front().first;
        if(tempMap[x][y] != -1) MAX = max(time, MAX);
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || tempMap[nx][ny] == -2 || visited[nx][ny] == 1) continue;
            if(tempMap[nx][ny] == 0){
                tempMap[nx][ny] = time+1;
                visited[nx][ny] = 1;
                q.push(make_pair(time+1, make_pair(nx,ny)));
            }else if(tempMap[nx][ny] == -1){
                visited[nx][ny] = 1;
                q.push(make_pair(time+1, make_pair(nx,ny)));
            }
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2) {
                v.push_back(make_pair(i,j));
                map[i][j] = -1;
            }if(map[i][j] == 1){
                map[i][j] = -2;
            }
        }
    }
    vector<int> s;
    int size = v.size();
    for(int i=0 ; i<M ; i++) s.push_back(1);
    for(int i=0 ; i<size-M ; i++) s.push_back(0);
    sort(s.begin(), s.end());
    do{
        sel.clear();
        MAX = -1;
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ;j++){
                tempMap[i][j] = map[i][j];
                visited[i][j] = 0;
            }
        }
        for(int i=0 ; i<size ; i++){
            if(s[i] == 1){
                tempMap[v[i].first][v[i].second] = 0;
                visited[v[i].first][v[i].second] = 1;
                sel.push_back(v[i]);
            }
        }
        bfs();
        if(check()){
            MIN = min(MAX, MIN);
        /*    printf("%d %d\n",MAX, MIN);
            for(int i=0 ; i<N ; i++){
                for(int j=0 ; j<N ; j++){
                    printf("%d ",tempMap[i][j]);
                }
                printf("\n");
            }*/
        }

    }while(next_permutation(s.begin(), s.end()));
    if(MIN == 987654321) MIN = -1;
    printf("%d\n",MIN);
}
