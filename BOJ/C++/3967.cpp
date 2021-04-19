#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

char map[6][11];
int cnt=0;
bool visited[13];
bool flag;
vector<pair<int, int>> v;
int size;
struct P{
    int r;
    int c;
}arr[12];

bool check(){
    if(map[0][4] + map[1][3] + map[2][2] + map[3][1] - 4*'A' + 4 != 26) return false;
    if(map[0][4] + map[1][5] + map[2][6] + map[3][7] - 4*'A' + 4 != 26) return false;
    if(map[1][1] + map[1][3] + map[1][5] + map[1][7] - 4*'A' + 4 != 26) return false;
    if(map[1][1] + map[2][2] + map[3][3] + map[4][4] - 4*'A' + 4 != 26) return false;
    if(map[1][7] + map[2][6] + map[3][5] + map[4][4] - 4*'A' + 4 != 26) return false;
    if(map[3][1] + map[3][3] + map[3][5] + map[3][7] - 4*'A' + 4 != 26) return false;
    return true;
}
void dfs(int idx, int now){

    if(idx == cnt){
        if(check()){
            flag = true;
        }
        return;
    }
    for(int i=0 ; i<12 ; i++){
        if(visited[i]) continue;

        visited[i] = true;
        map[arr[now].r][arr[now].c] = 'A'+i;
        dfs(idx+1, now+1);
        if(flag) return;
        visited[i] = false;
        map[arr[now].r][arr[now].c] = 'x';
    }
}
int main(){
    for(int i=0 ; i<5 ; i++){
        scanf("%s",map[i]);
    }
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<8 ; j++){
            if(map[i][j] >= 'A' && map[i][j] <= 'L'){
                visited[map[i][j] - 'A'] = true;
            }
            else if(map[i][j] == 'x') {
                arr[cnt].r = i;
                arr[cnt].c = j;
                cnt++;
            }
        }
    }
    size = v.size();
    dfs(0,0);
    for(int i=0 ; i<5 ; i++){
        printf("%s\n",map[i]);
    }
}
