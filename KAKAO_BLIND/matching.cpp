#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
bool comp(string a, string b){
    if(a.size() == b.size()) return a<b;
    return a.size() < b.size();
}
bool comp2(string a, string b){
    return a.size() < b.size();
}
int getWords(vector<string> words, string str){
    int u = upper_bound(words.begin(),words.end(),str,comp2) - words.begin();
    int l = lower_bound(words.begin(),words.end(),str,comp2) - words.begin();
    int cnt = 0;
    int c=0;
    int end = 0;
    if(str[0] == '?'){
        while(str[c] == '?') c++;
        end = str.size();
    }else{
        while(str[c] != '?') c++;
        end = c;
        c = 0;
    }
    for(int i=l ; i<u ; i++){
        bool flag = true;
        for(int j=c ; j<end ; j++){
            if(str[j] != words[i][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt++;
        }
    }
    return cnt;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<pair<string, int>> q;
    map<string, int> m;
    map<string, int> m2;
    sort(words.begin(), words.end(), comp);

    for(int i=0 ; i<queries.size() ; i++){
        m[queries[i]]=1;
    }
    for(auto it = m.begin() ; it != m.end() ; it++){
        m2[it->first] = getWords(words,it->first);
    }
    for(int i=0 ; i<queries.size() ; i++){
        answer.push_back(m2[queries[i]]);
    }
    return answer;
}
