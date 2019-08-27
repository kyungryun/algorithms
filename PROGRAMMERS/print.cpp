#include <string>
#include <deque>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> v;
    int size = priorities.size();
    int MAX = 0;
    for(int i=0 ; i<size ; i++){
        v.push_back(make_pair(priorities[i],i));
        MAX = max(MAX, priorities[i]);
    }
    while(1){
        int now = v.front().first;
        int loc = v.front().second;
        if(now >= MAX){
            v.pop_front();
            answer++;
            if(loc == location) break;
            MAX = 0;
            for(int i=0 ; i<v.size() ; i++){
                MAX = max(MAX, v[i].first);
            }
        }else{
            v.pop_front();
            v.push_back(make_pair(now,loc));
        }
    }
    return answer;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(9);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    printf("%d\n",solution(v, 0));
}
