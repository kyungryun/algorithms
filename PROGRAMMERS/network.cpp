#include <string>
#include <vector>

using namespace std;
bool visited[201];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int n;
void dfs(int idx, vector<vector<int>>&map){
    visited[idx] = true;
    for(int i=0 ; i<n ; i++){
        if(!visited[i] && map[idx][i] == 1) dfs(i, map);
    }
}
int solution(int computer, vector<vector<int>> computers) {
    int answer = 0;
    n = computer;
    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            dfs(i,computers);
            answer++;
        }
    }
    return answer;
}
