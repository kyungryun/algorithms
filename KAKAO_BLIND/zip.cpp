#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int zip(int n, string s){
    vector<string> str;
    string res = "";
    while(s.size() != 0){
        if(n > s.size()){
            str.push_back(s);
            break;
        }
        str.push_back(s.substr(0,n));
        s = s.substr(n);
    }
    for(int i=0 ; i<str.size() ; ){
        int cnt = 1;
        int j;
        for(j=i+1 ; j<str.size() ; j++){
            if(str[i] == str[j]) {
                cnt++;
            }else{
                break;
            }
        }
        if(cnt == 1) res += str[i];
        else{
            res += (to_string(cnt)+str[i]);
        }
        i=j;
    }

    return res.size();
}
int solution(string s) {
    int answer = s.size();
    for(int i=1 ; i<=s.size()/2 ; i++){
        answer = min(answer,zip(i, s));
    }
    return answer;
}

int main(){
    string s = "abcabcabcabcdededededede";
    string s2 = "abcabcdede";
    cout<<solution(s2)<<endl;
}
