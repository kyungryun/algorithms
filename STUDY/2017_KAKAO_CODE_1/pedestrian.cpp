#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int r[501][501];
    int c[501][501];
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    r[1][1] = c[1][1] = 1;
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            if(city_map[i-1][j-1] == 0){
                r[i][j] += (r[i-1][j] + c[i][j-1]) % MOD;
                c[i][j] += (r[i-1][j] + c[i][j-1]) % MOD;
            }else if(city_map[i-1][j-1] == 1){
                r[i][j] = 0;
                c[i][j] = 0;
            }else{
                r[i][j] += r[i-1][j];
                c[i][j] += c[i][j-1];
            }
        }
    }
    answer = (r[m][n])%MOD;
    return answer;
}

int main(){
    vector<vector<int>> v = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    vector<vector<int>> v2 = {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};

    printf("%d\n",solution(3,3,v)%MOD);
    printf("%d\n",solution(3,6,v2)%MOD);
}
/*
3 3
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}

3 6
{{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}
*/
