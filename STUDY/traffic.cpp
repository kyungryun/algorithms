// 트래픽

#include <string>
#include <vector>

using namespace std;

pair<long long, int> split(string str){
    long long hour = ((str[0] - '0')*10 + (str[1] - '0'))*60*60*1000;
    long long min = ((str[3] - '0')*10 + (str[4] - '0'))*60*1000;
    long long sec = ((str[6] - '0')*10 + (str[7] - '0'))*1000;
    sec += ((str[9]-'0')*100 + (str[10] - '0')*10 + str[11]-'0');
    string t = str.substr(14);
    int time = (str[13]-'0')*1000;
    int ms = 0;
    for(int i=0 ; i<t.size() ; i++){
        if(t[i] >= '0' && t[i] <= '9'){
            ms*=10;
            ms+=(t[i]-'0');
        }
    }

    return make_pair(hour+min+sec, time+ms);
}
int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<long long, int>> v;
    for(int i=0 ; i<lines.size() ; i++){
        v.push_back(split(lines[i].substr(11)));
    }

    for(int i=v.front().first-v.front().second+1 ; i<v.back().first ; i+=1000){
        int s = 0;
        for(auto it=v.begin() ; it != v.end() ; it++){
            if(it->first >= i && it->first <= i+1000) s++;
            else if((it->first - it->second +1) >= i && (it->first - it->second+1) <= i + 1000)s++;
        }
        answer = max(s, answer);
    }
    return answer;
}

int main(){

}
