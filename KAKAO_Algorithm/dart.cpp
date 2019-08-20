#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3];
    int size = dartResult.size();
    int cnt = -1;
    for(int i=0 ; i<size ; i++){
        if(isdigit(dartResult.at(i))){
            cnt++;
            if(dartResult.at(i+1) == '0'){
                score[cnt] = (dartResult.at(i)-'0')*10;
                i++;
            }else{
                score[cnt] = dartResult.at(i)-'0';
            }
        }else{
            if(dartResult.at(i) == 'S'){
                continue;
            }else if(dartResult.at(i) == 'D'){
                score[cnt] *= score[cnt];
            }else if(dartResult.at(i) == 'T'){
                int t = score[cnt];
                for(int i=0 ; i<2 ; i++) score[cnt]*=t;
            }else if(dartResult.at(i) == '*'){
                if(cnt == 0) score[cnt] *= 2;
                else{
                    score[cnt] *= 2;
                    score[cnt-1] *= 2;
                }
            }else{
                score[cnt] *= -1;
            }
        }
    }
    answer = score[0]+score[1]+score[2];
    return answer;
}
int main(){
    string str;
    cin>>str;
    cout<<solution(str)<<"\n";
}
