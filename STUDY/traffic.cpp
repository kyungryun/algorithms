// 트래픽

#include <string>
#include <vector>

using namespace std;

struct Log{
    long long sTime;
    long long eTime;
};
Log split(string str){
    Log log;
    long long hour = ((str[0] - '0')*10 + (str[1] - '0'))*60*60*1000;
    long long min = ((str[3] - '0')*10 + (str[4] - '0'))*60*1000;
    long long sec = ((str[6] - '0')*10 + (str[7] - '0'))*1000;
    sec += ((str[9]-'0')*100 + (str[10] - '0')*10 + str[11]-'0');
    long long totalTime = hour+min+sec;
    string t = str.substr(14);
    int time = (str[13]-'0')*1000;
    int ms = 0;
    for(int i=0 ; i<t.size() ; i++){
        if(t[i] >= '0' && t[i] <= '9'){
            ms*=10;
            ms+=(t[i]-'0');
        }
    }
    ms += time;
    log.sTime = totalTime - ms + 1;
    log.eTime = totalTime;
    return log;
}
int solution(vector<string> lines) {
    int answer = 1;
    vector<Log> v;
    for(int i=0 ; i<lines.size() ; i++){
        v.push_back(split(lines[i].substr(11)));
    }

    for(int i=0 ; i<lines.size()-1 ; i++){
        int eTime = v[i].eTime;
        int cnt = 1;
        for(int j=i+1 ; j<lines.size() ; j++){
            if(v[j].sTime <= eTime+999 && eTime <= v[j].eTime) cnt++;
        }
        answer = max(cnt, answer);
    }
    return answer;
}

int main(){

}
