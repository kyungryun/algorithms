#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
int solution(vector<vector<string>> clothes) {
    int answer = clothes.size();
    for(int i=0 ; i<clothes.size() ; i++){
        m[clothes[i][1]]++;
    }
    auto it = m.begin();
    answer = it->second;
    for(it++ ; it != m.end() ; it++){
        answer+=(answer+1)*it->second;
    }
    return answer;
}
