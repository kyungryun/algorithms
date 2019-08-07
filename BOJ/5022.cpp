#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<pair<int, int>> A(2);
vector<pair<int, int>> B(2);
bool visited[101][101];
bool complete[101][101];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
bool bfs(int sr, int sc, int er, int ec, int ab){
    queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
    vector<pair<int, int>> path;
    path.push_back(make_pair(sr,sc));
    q.push(make_pair(make_pair(sr,sc),path));
    visited[sr][sc] = true;
    complete[sr][sc] = true;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        vector<pair<int, int>> v = q.front().second;
        int size = v.size();
        q.pop();

        if(r == er && c == ec){
            for(int i=0 ; i<size ; i++){
                complete[v[i].first][v[i].second] = true;
            }
            return true;
        }

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            vector<pair<int, int>> tmp;
            for(int j=0 ; j<size ; j++) tmp.push_back(v[j]);

            if(nr < 0 || nr > n || nc < 0 || nc > m) continue;
            if(ab == 1 && ((nr == B[0].first && nc == B[0].second) || (nr == B[1].first && nc == B[1].second))) continue;
            if(ab == 2 && ((nr == A[0].first && nc == A[0].second) || (nr == A[1].first && nc == A[1].second))) continue;
            if(!visited[nr][nc] && !complete[nr][nc]){
                tmp.push_back(make_pair(nr,nc));
                q.push(make_pair(make_pair(nr,nc),tmp));
                visited[nr][nc] = true;
            }

        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0 ; i<2 ; i++){
        scanf("%d%d",&a,&b);
        A[i].first = a;
        A[i].second = b;
    }
    for(int i=0 ; i<2 ; i++){
        scanf("%d%d",&a,&b);
        B[i].first = a;
        B[i].second = b;
    }
    int ans = 987654321;
    int cnt=0;
    bool flag, flag2;
    flag = bfs(A[0].first, A[0].second, A[1].first, A[1].second, 1);
    memset(visited,false,sizeof(visited));
    flag2 = bfs(B[0].first, B[0].second, B[1].first, B[1].second,2);

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(complete[i][j]) cnt++;
        }
    }
    //printf("%d %d %d\n",cnt, flag, flag2);
    if(flag && flag2) ans = min(ans, cnt-2);

    memset(visited,false,sizeof(visited));
    memset(complete,false,sizeof(complete));

    flag = bfs(B[0].first, B[0].second, B[1].first, B[1].second,2);
    memset(visited,false,sizeof(visited));
    flag2 = bfs(A[0].first, A[0].second, A[1].first, A[1].second, 1);
    cnt = 0;
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(complete[i][j]) cnt++;
        }
    }
    if(flag && flag2) ans = min(ans, cnt-2);

    if(ans == 987654321) printf("IMPOSSIBLE\n");
    else printf("%d\n",ans);
}
