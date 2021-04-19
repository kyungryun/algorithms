#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m,k;
int map[102][102];
bool visited[102][102];
int x1,y1,x2,y2;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int area;
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0 ; i<k ; i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int y=y1 ; y<y2 ; y++){
            for(int x=x1 ; x<x2 ; x++){
                map[y][x] = 1;
            }
        }
    }
    vector<int> v;
    for(int i=m-1 ; i>=0 ; i--){
        for(int j=0 ; j<n ; j++){
            if(map[i][j] == 0 && !visited[i][j]){
                int cnt = 1;
                area++;
                queue<pair<int, int>> q;
                q.push(make_pair(i,j));
                visited[i][j] = true;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int k=0 ; k<4 ; k++){
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(nr < 0 || nc < 0 || nr >= m || nc >= n || map[nr][nc] == 1) continue;
                        if(!visited[nr][nc]){
                            visited[nr][nc] = true;
                            q.push(make_pair(nr,nc));
                            cnt++;
                        }
                    }
                }
                v.push_back(cnt);
            }
        }
    }
    printf("%d\n",area);
    sort(v.begin(), v.end());
    for(int i=0 ; i<v.size() ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
