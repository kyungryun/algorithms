// 프렌즈 4블록
// https://programmers.co.kr/learn/courses/30/lessons/17679

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int block[31][31];
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int now;
    while(1){
        now = 0;
        memset(block,0,sizeof(block));
        for(int i=0 ; i<m-1 ; i++){
            for(int j=0 ; j<n-1 ; j++){
                if(board[i][j] >= 'A' && board[i][j] <= 'Z'){
                    char c = board[i][j];
                    if(board[i][j+1] == c && board[i+1][j+1] == c && board[i+1][j] == c){
                        block[i][j] = 1;
                        block[i][j+1] = 1;
                        block[i+1][j] = 1;
                        block[i+1][j+1] = 1;
                    }
                }
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(block[i][j] == 1){
                    board[i][j] = ' ';
                    now++;
                }
            }
        }

        if(now == 0) break;

        for(int i=0 ; i<n ; i++){
            string str = "";
            for(int j=m-1 ; j>=0 ; j--){
                if(board[j][i] != ' ') {
                    str += board[j][i];
                    board[j][i] = ' ';
                }
            }
            for(int j=0 ; j<str.size() ; j++){
                board[m-1-j][i] = str[j];
            }
        }
        answer += now;
    }
    return answer;
}

int main(){
    vector<string>v;
    int n,m;
    cin>>m>>n;
    string str;
    for(int i=0 ; i<m ; i++) {
        cin>>str;
        v.push_back(str);
    }
    cout<<solution(m,n,v)<<endl;
}


/*
4 5
CCBDE
AAADE
AAABF
CCBBF

6 6
TTTANT
RRFACC
RRRFCC
TRRRAA
TTMMMF
TMMTTJ
*/
