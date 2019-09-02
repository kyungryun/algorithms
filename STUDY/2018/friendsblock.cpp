#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool fill(int r, int c, vector<vector<int>> &board){
    for(int i=0 ; i<r ; i++){
        if(board[i][c] != 0) return false;
    }
    return true;
}
bool check(int r, int c, int h, int w, vector<vector<int>> &board){
    int cnt = 0;
    int now = -1;
    for(int i=r ; i<r+h ; i++){
        for(int j=c ; j<c+w ; j++){
            if(board[i][j] == 0){
                if(!fill(i,j,board)) return false;
                if(cnt >= 2) return false;
                cnt++;
            }else{
                if(now != -1 && now != board[i][j]) return false;
                now = board[i][j];
            }
        }
    }

    for(int i=r ; i<r+h ; i++){
        for(int j=c ; j<c+w ; j++){
            board[i][j] = 0;
        }
    }
    return true;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    while(1){
        int cnt = 0;
        for(int i=0 ; i<size ; i++){
            for(int j=0 ; j<size ; j++){
                if(i+3 <= size && j+2 <= size && check(i,j,3,2,board)){
                    cnt++;
                }else if(i+2 <= size && j+3 <= size && check(i,j,2,3,board)){
                    cnt++;
                }
            }
        }
        if(cnt == 0) return answer;
        else answer += cnt;
    }
    return answer;
}


int main(){
    vector<vector<int>> v;
    int n;
    scanf("%d",&n);
    int t;
    for(int i=0 ; i<n ; i++){
        vector<int> tmp;
        for(int j=0 ; j<n ; j++){
            scanf("%d",&t);
            tmp.push_back(t);
        }
        v.push_back(tmp);
    }

    printf("%d\n",solution(v));
}

/*
10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 4 0 0 0
0 0 0 0 0 4 4 0 0 0
0 0 0 0 3 0 4 0 0 0
0 0 0 2 3 0 0 0 5 5
1 2 2 2 3 3 0 0 0 5
1 1 1 0 0 0 0 0 0 5
*/
