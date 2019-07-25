#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int dr[4] = {0,-1,0,1};
int dc[4] = {1,0,-1,0};
char str[21][21];
bool visited[21][21][16][4];
int R,C;
struct Node{
    int r;
    int c;
    int mem;
    int dir;
};
bool bfs(){
    queue<Node> q;
    Node node = {0,0,0,0};
    q.push(node);
    visited[0][0][0][0] = true;
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int mem = q.front().mem;
        int dir = q.front().dir;
        q.pop();

        if(str[r][c] == '@') return true;
        else if(str[r][c] == '<')dir = 2;
        else if(str[r][c] == '>')dir = 0;
        else if(str[r][c] == '^')dir = 1;
        else if(str[r][c] == 'v')dir = 3;
        else if(str[r][c] == '_'){
            if(mem == 0) dir = 0;
            else dir = 2;
        }else if(str[r][c] == '|'){
            if(mem == 0) dir = 3;
            else dir = 1;
        }else if(str[r][c] == '+'){
            if(mem == 15) mem = 0;
            else mem++;
        }else if(str[r][c] == '-'){
            if(mem == 0) mem = 15;
            else mem--;
        }else if(isdigit(str[r][c])){
            mem = str[r][c] - '0';
        }else if(str[r][c] == '?'){
            for(int i=0 ; i<4 ; i++){
                int nc = c + dc[i];
                int nr = r + dr[i];

                if(nr < 0) nr = R-1;
                else if(nr == R) nr = 0;
                if(nc < 0) nc = C-1;
                else if(nc == C) nc = 0;

                if(!visited[nr][nc][mem][i]){
                    Node n = {nr,nc,mem,i};
                    q.push(n);
                    visited[nr][nc][mem][i] = true;
                }
            }
        }

        int nc = c + dc[dir];
        int nr = r + dr[dir];
        if(nr < 0) nr = R-1;
        else if(nr == R) nr = 0;
        if(nc < 0) nc = C-1;
        else if(nc == C) nc = 0;

        if(!visited[nr][nc][mem][dir]){
            Node n = {nr,nc,mem,dir};
            q.push(n);
            visited[nr][nc][mem][dir] = true;
        }
    }

    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int T=1 ; T<=t ; T++){
        memset(visited, false, sizeof(visited));
        string ans;

        scanf("%d%d",&R,&C);
        for(int i=0 ; i<R ; i++){
            scanf("%s",str[i]);
        }
        if(bfs()) ans = "YES";
        else ans = "NO";
        cout<<"#"<<T<<" "<<ans<<endl;
    }
}
