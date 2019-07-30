#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int N;
int ans,coreNum;
int map[13][13];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
vector<pair<int, int> > core;
vector<int> v;
int MIN = 987654321;
int MAX = -1;
int calc(){
    int cnt = 0;

    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(map[i][j] == 2) cnt++;
        }
    }
    return cnt;
}
bool check(int r, int c){
    bool flag[4] = {false};
    for(int i=0 ; i<4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) flag[i] = true;
        else if(map[nr][nc] == 1) flag[i] = true;
    }
    for(int i=0 ; i<4 ; i++){
        if(!flag[i]) return true;
    }
    return false;
}
bool isConnect(int r, int c, int d){
    int nr = r+ dr[d];
    int nc = c + dc[d];
    while(1){
        if( nr < 0 || nr >= N || nc < 0 || nc >= N)break;
        if(map[nr][nc] >= 1) return false;
        nr += dr[d];
        nc += dc[d];
    }
    return true;
}
void connect(int r, int c, int d, int num){
    int nr = r+ dr[d];
    int nc = c + dc[d];
    while(1){
        if( nr < 0 || nr >= N || nc < 0 || nc >= N) break;
        map[nr][nc] += num;
        nr += dr[d];
        nc += dc[d];
    }
}
void dfs(int n, int coreCnt){
    if(n == core.size()){
        if(MAX < coreCnt){
            MAX = coreCnt;
            MIN = calc();
        }else if(MAX == coreCnt) MIN = min(MIN, calc());
        return;
    }
    int r = core[n].first;
    int c = core[n].second;
    for(int i=0 ; i<4 ; i++){
        if(isConnect(r,c,i)){
            connect(r,c,i,2);
            dfs(n+1, coreCnt+1);
            connect(r,c,i,-2);
        }
    }
    dfs(n+1, coreCnt);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int T=1 ; T<=t ; T++){
        scanf("%d",&N);
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                if(i == 0 || i == N-1 || j == 0 || j == N-1) continue;
                if(map[i][j] == 1 && check(i,j)) {
                    core.push_back(make_pair(i,j));
                }
            }
        }
        dfs(0,0);
        if(MIN == 987654321) ans = 0;
        else ans = MIN;
        printf("#%d %d\n",T,ans);
        core.clear();
        ans = coreNum = 0;
        MIN = 987654321;
        MAX = -1;
    }
}
