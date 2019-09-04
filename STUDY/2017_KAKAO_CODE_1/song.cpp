#include <cmath>

int dfs(int n, int e){
    if(n < 1 || 2*log(n)/log(3) < e) return 0;
    if(n == 3) return e == 2;
    int res = 0;
    if(n%3 == 0 && e >= 2) res += dfs(n/3, e-2);
    res += dfs(n-1, e+1);
    return res;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    int answer = 0;

    answer = dfs(n-2,2);
    return answer;
}
