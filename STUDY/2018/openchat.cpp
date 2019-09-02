#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> list;
pair<string, string> split(string str){
    vector<string> v;
    int s = 0;
    int i=0;
    int cnt = 0;
    for(int i=0 ; i<str.size() ; i++){
        if(str[i] == ' '){
            v.push_back(str.substr(s,cnt));
            s = i+1;
            i++;
            cnt = 0;
        }
        cnt++;
    }
    v.push_back(str.substr(s));
    if(v[0] != "Leave") {
        list[v[1]] = v[2];
    }
    return make_pair(v[0], v[1]);
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> log;
    for(int i=0 ; i<record.size() ; i++){
        log.push_back(split(record[i]));
    }
    for(int i=0 ; i<record.size() ; i++){
        if(log[i].first == "Enter"){
            answer.push_back(list[log[i].second]+"님이 들어왔습니다.");
        }else if(log[i].first == "Leave"){
            answer.push_back(list[log[i].second]+"님이 나갔습니다.");
        }
    }
    return answer;
}
