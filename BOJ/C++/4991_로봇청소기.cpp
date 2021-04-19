#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 987654321;
int w,h;
int room[21][21];
bool visited[21][21];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int ans;
int sr,sc;
int dist[12][21][21];

int main(){
    while(1){
        scanf("%d%d",&w,&h);
        if(w==0 && h==0) break;
        char str[21][21];
        for(int i=0 ; i<h; i++){
            scanf("%s",str[i]);
        }
        deque<pair<int, int>> dq;
        for(int i=0 ; i<h ; i++){
            for(int j=0 ; j<w ; j++){
                if(str[i][j] == '.') room[i][j] = 0;
                else if(str[i][j] == '*') {
                    dq.push_back(make_pair(i,j));
                    room[i][j] = 2;
                }else if(str[i][j] == 'x') room[i][j] = 1;
                else{
                    sr = i, sc = j;
                    room[i][j] = 2;
                    dq.push_front(make_pair(i,j));
                }
            }
        }
        memset(dist, -1, sizeof(dist));
        for(int i=0 ; i<dq.size(); i++){
            int rr = dq[i].first;
            int cc = dq[i].second;

            queue<pair<int, int>> q;
            q.push(make_pair(rr,cc));
            dist[i][rr][cc] = 0;
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k=0 ; k<4 ; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
                    if(room[nr][nc] == 1) continue;
                    if(dist[i][nr][nc] != -1) continue;
                    dist[i][nr][nc] = dist[i][r][c] + 1;
                    q.push(make_pair(nr,nc));
                }
            }
        }
        vector<int> v;
        for(int i=0 ; i<dq.size() ; i++){
            v.push_back(i);
        }
        int ans = -1;
        do{
            int sum = 0;
            int now = 0;
            bool flag = true;
            for(int i=1 ; i<v.size() ; i++){
                if(dist[now][dq[v[i]].first][dq[v[i]].second] == -1){
                    flag = false;
                    break;
                }
                sum += dist[now][dq[v[i]].first][dq[v[i]].second];
                now = v[i];
            }
            if(flag && (ans == -1 || ans > sum)) ans = sum;
        }while(next_permutation(v.begin()+1, v.end()));
        printf("%d\n",ans);
    }
}
