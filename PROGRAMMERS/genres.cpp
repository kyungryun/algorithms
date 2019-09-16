#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
bool comp2(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> m;
    map<string, int> m2;
    vector<pair<int, string>> v;
    for(int i=0 ; i<genres.size() ; i++){
        m2[genres[i]] += plays[i];
        m[genres[i]].push_back(make_pair(i,plays[i]));
    }
    for(auto it=m2.begin() ; it != m2.end() ; it++){
        v.push_back(make_pair(it->second, it->first));
    }
    sort(v.begin(), v.end(), comp2);

    for(int i=0 ; i<v.size() ; i++){
        auto now = m[v[i].second];
        sort(now.begin(), now.end(), comp);
        answer.push_back(now[0].first);
        if(now.size() > 1) answer.push_back(now[1].first);
    }
    return answer;
}
