#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> a, pair<double, int>b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    int size = stages.size();
    vector<pair<double, int>> v;
    for(int i=1 ; i<=N ; i++){
        int l = lower_bound(stages.begin() , stages.end(), i) - stages.begin();
        int u = upper_bound(stages.begin() , stages.end(), i) - stages.begin();
        if(u-l == 0) v.push_back(make_pair(0,i));
        else{
            v.push_back(make_pair((u-l)/(double)size, i));
        }
        size -= (u-l);
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0 ; i<v.size() ; i++){
        answer.push_back(v[i].second);
    }
    return answer;
}
