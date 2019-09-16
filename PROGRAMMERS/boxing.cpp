#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

bool flag[101];
int scores[101][101];
int INF = 987654321;
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    memset(flag, true, sizeof(flag));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i != j) scores[i][j] = INF;
            else scores[i][j] = 0;
        }
    }
    for(int i=0 ; i<results.size() ; i++){
        scores[results[i][0]-1][results[i][1]-1] = 1;
    }

    for(int k=0 ; k<n ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                scores[i][j] = min(scores[i][j], scores[k][j] + scores[i][k]);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i == j) continue;
            if(scores[i][j] == INF && scores[j][i] == INF){
                flag[i] = false;
                break;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(flag[i]) answer++;
    }
    return answer;
}
int main(){
    vector<vector<int>> v = {{4,3},{4,2},{3,2},{1,2},{2,5}};

    cout<<solution(5,v)<<endl;
}
