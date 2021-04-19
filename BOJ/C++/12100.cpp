#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[21][21];
int N;
int ans;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void mapCopy(int(*a)[21],int(*b)[21]){
    for(int i=0 ; i< N ; i++){
        for(int j=0 ; j<N ; j++){
            a[i][j] = b[i][j];
        }
    }
}
void move(int dir){
    queue<int> q;
    int idx;
    int num;
    if(dir == 0){
        for(int i=0 ; i<N ; i++){
            for(int j=N-1 ; j>=0 ; j--){
                if(map[i][j] != 0) q.push(map[i][j]);
                map[i][j] = 0;
            }
            idx = N-1;
            while(!q.empty()){
                num = q.front();
                q.pop();
                if(map[i][idx] == 0) map[i][idx] = num;
                else if(map[i][idx] == num){
                    map[i][idx] *=2;
                    idx--;
                }else{
                    map[i][--idx] = num;
                }
            }
        }
    }else if(dir == 1){
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                if(map[i][j] != 0) q.push(map[i][j]);
                map[i][j] = 0;
            }
            idx = 0;
            while(!q.empty()){
                num = q.front();
                q.pop();
                if(map[i][idx] == 0) map[i][idx] = num;
                else if(map[i][idx] == num){
                    map[i][idx] *=2;
                    idx++;
                }else map[i][++idx] = num;
            }
        }
    }else if(dir == 2){
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                if(map[j][i] != 0) q.push(map[j][i]);
                map[j][i] = 0;
            }
            idx = 0;
            while(!q.empty()){
                num = q.front();
                q.pop();
                if(map[idx][i] == 0) map[idx][i] = num;
                else if(map[idx][i] == num){
                    map[idx][i] *= 2;
                    idx++;
                }else map[++idx][i] = num;
            }
        }
    }else{
        for(int i=0 ; i<N ; i++){
            for(int j=N-1 ; j>=0 ; j--){
                if(map[j][i] != 0) q.push(map[j][i]);
                map[j][i] = 0;
            }
            idx = N-1;
            while(!q.empty()){
                num = q.front();
                q.pop();
                if(map[idx][i] == 0) map[idx][i] = num;
                else if(map[idx][i] == num){
                    map[idx][i] *= 2;
                    idx--;
                }else map[--idx][i] = num;
            }
        }
    }
}
void dfs(int cnt){
    if(cnt == 5){
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                ans = max(ans, map[i][j]);
            }
        }
        return;
    }

    int temp[21][21];
    mapCopy(temp, map);
    for(int i=0 ; i<4 ; i++){
        move(i);
        dfs(cnt+1);
        mapCopy(map, temp);
    }
}
int main(){
    scanf("%d",&N);
    int a;
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            scanf("%d",&map[i][j]);
        }
    }
    dfs(0);
    printf("%d\n",ans);
}
