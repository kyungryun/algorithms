#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int map[13][7];
int chain;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool bomb(int r, int c){
    queue<pair<int, int>> q;
    vector<pair<int, int>> color;
    q.push(make_pair(r,c));
    color.push_back(make_pair(r,c));
    int visited[13][7];
    memset(visited,0,sizeof(visited));
    visited[r][c] = 1;
    while(!q.empty()){
        int rr = q.front().first;
        int cc = q.front().second;

        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = rr + dr[i];
            int nc = cc + dc[i];

            if(nr < 0 || nr >= 12 || nc < 0 || nc >= 6 || visited[nr][nc]) continue;
            if(map[rr][cc] != map[nr][nc]) continue;
            q.push(make_pair(nr,nc));
            visited[nr][nc] = 1;
            color.push_back(make_pair(nr,nc));
        }
    }
    int size = color.size();
    if(size >= 4){
        for(int i=0 ; i<size ; i++){
            map[color[i].first][color[i].second] = 0;
        }
        return true;
    }
    return false;
}
void move(){
    for(int j=0 ; j<6 ; j++){
        queue<int> q;
        for(int i=11 ; i>=0 ; i--){
            if(map[i][j] > 0){
                q.push(map[i][j]);
                map[i][j] = 0;
            }
        }
        int i = 11;
        while(!q.empty()){
            map[i--][j] = q.front();
            q.pop();
        }
    }

}
int main(){
    char a[7];
    for(int i=0 ; i<12 ; i++){
        scanf("%s",a);
        for(int j=0 ; j<6 ; j++){
            //Red 1 Green 2 Blue 3 Violet 4 Yellow 5
            if(a[j] == '.') map[i][j] = 0;
            else if(a[j] == 'R') map[i][j] = 1;
            else if(a[j] == 'G') map[i][j] = 2;
            else if(a[j] == 'B') map[i][j] = 3;
            else if(a[j] == 'P') map[i][j] = 4;
            else if(a[j] == 'Y') map[i][j] = 5;
        }
    }
    while(1){
        int cnt = 0;
        for(int i=0 ; i<12 ; i++){
            for(int j=0 ; j<6 ; j++){
                if(map[i][j] != 0){
                    if(bomb(i,j)){
                        //printf("%d %d\n",i,j);
                        cnt++;
                    }
                }
            }
        }
        //printf("cnt %d\n",cnt);
        if(cnt == 0) break;
        else{
            move();
            chain++;
        }
    }


    printf("%d\n",chain);
}
