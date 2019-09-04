#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int bfs(int r, int c, int m, int n, vector<vector<int>>&picture, bool (*visited)[101] ){
    queue<pair<int, int>> q;
    q.push(make_pair(r,c));
    visited[r][c] = true;
    int size = 1;
    while(!q.empty()){
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nr = rr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;
            if(picture[rr][cc] == picture[nr][nc]){
                visited[nr][nc] = true;
                size++;
                q.push(make_pair(nr,nc));
            }
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool visited[101][101];
    memset(visited,false,sizeof(visited));
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(visited[i][j] || picture[i][j] == 0) continue;
            max_size_of_one_area = max(max_size_of_one_area,bfs(i,j,m,n,picture,visited));
            number_of_area++;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<vector<int>> v = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    vector<int> ans = solution(6,4,v);
    for(int i=0 ; i<ans.size() ; i++){
        printf("%d\n",ans[i]);
    }
}
/*
6 4
{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
*/
