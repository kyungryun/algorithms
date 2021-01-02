#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int h = triangle.size();
    int dp[501][501];
    dp[0][0] = triangle[0][0];
    for(int i=1 ; i<h ; i++){
        int size = triangle[i].size();
        for(int j=0 ; j<size ; j++){
            if(j-1 < 0) dp[i][j] = triangle[i][j] + dp[i-1][j];
            else if(j == size-1) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            else dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    for(int i=0 ; i<h ; i++){
        answer = max(answer, dp[h-1][i]);
    }
    return answer;
}
