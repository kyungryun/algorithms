
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n;
int ans=200;
int map[101][101];
int MIN = 200;
int MAX = 0;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
bool bfs(int mid){
    bool visited[101][101];
    queue<pair<int, int>> q;
    for(int i=MIN ; i <=MAX ; i++){

        memset(visited,true,sizeof(visited));

        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<n ; k++){
                if(map[j][k] >= i && map[j][k] <= i + mid) visited[j][k] = false;
            }
        }

        q.push(make_pair(0,0));
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(visited[r][c]) continue;
            visited[r][c] = true;

            if(r == n-1 && c == n-1) return true;

            for(int j=0 ; j<4;  j++){
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr >=0 && nr < n && nc >= 0 && nc < n ){
                    q.push(make_pair(nr,nc));
                }

            }
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d",&map[i][j]);
            MIN = min(MIN,map[i][j]);
            MAX = max(MAX,map[i][j]);
        }
    }
    int left = 0;
    int right = MAX-MIN;
    while(left <= right){
        int mid = (left + right)/2;
        if(bfs(mid)){
            right = mid-1;
            ans = min(ans,mid);
        }else{
            left = mid+1;
        }
    }
    printf("%d\n",ans);
}
