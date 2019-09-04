#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    vector<int> t;
    vector<int> c;
    int chk = 0;
    for(int i=0 ; i<data.size(); i++){
        t.push_back(data[i][0]);
        c.push_back(data[i][1]);
    }
    sort(t.begin(), t.end());
    sort(c.begin(), c.end());

    vector<int> r;
    r.push_back(t[0]);
    int idx = 0;
    for(int i=1 ; i<t.size() ; i++){
        if(r[idx] != t[i]){
            r.push_back(t[i]);
            idx++;
        }
    }

    //r.erase(unique(r.begin(),r.end()),r.end());
    c.erase(unique(c.begin(),c.end()),c.end());

    int sum[5001][5001];
    memset(sum,0,sizeof(sum));
    for(int i=0 ; i<data.size() ; i++){
        for(int j=0 ; j<r.size() ; j++){
            if(data[i][0] == r[j]){
                data[i][0] = j;
                break;
            }
        }
        for(int j=0 ; j<c.size() ; j++){
            if(data[i][1] == c[j]){
                data[i][1] = j;
                break;
            }
        }
        sum[data[i][0]][data[i][1]] = 1;
    }


    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i-1 >= 0) sum[i][j] += sum[i-1][j];
            if(j-1 >= 0) sum[i][j] += sum[i][j-1];
            if(i-1 >=0 && j-1>=0) sum[i][j] -= sum[i-1][j-1];

        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            int sr,sc,er,ec;

            sr = min(data[i][0],data[j][0]);
            sc = min(data[i][1],data[j][1]);
            er = max(data[i][0],data[j][0]);
            ec = max(data[i][1],data[j][1]);

            int cnt = 0;
            if(sr + 1 > er - 1 || sc + 1 > ec - 1) cnt = 0;
            else{
                cnt = sum[er-1][ec-1] - sum[er-1][sc] - sum[sr][ec-1] + sum[sr][sc];
            }
            if(cnt == 0) answer++;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> data = {{0,0}, {1,1}, {0,2}, {2,0}, {0,3}, {3,2}, {1,4}, {4,4}, {100, 50}, {150, 30}};
    printf("%d\n",solution(data.size(),data));
}
