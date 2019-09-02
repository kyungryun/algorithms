#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int count(int n){
    int cnt = 0;
    while(n){
        if(n&1) cnt++;
        n = n>>1;
    }
    return cnt;
}
bool comp(int a, int b){
    return count(a) > count(b);
}
int check(int attribute, int tuple, vector<vector<string>> &relation, int sub){
    for(int i=0 ; i<tuple-1 ; i++){
        for(int j=i+1 ; j<tuple ; j++){
            bool flag = true;
            for(int k=0 ; k<attribute ; k++){
                if((sub&1<<k) == 0) continue;
                if(relation[i][k] != relation[j][k]){
                    flag = false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int attribute = relation[0].size();
    int tuple = relation.size();
    int n = 1<<attribute;
    vector<int> v;
    for(int i=1 ; i<1<<attribute ; i++){
        if(check(attribute,tuple,relation,i)) v.push_back(i);
    }
    sort(v.begin(),v.end(),comp);
    while(!v.empty()){
        int last = v.back();
        v.pop_back();
        answer++;
        for(vector<int>::iterator it = v.begin() ; it != v.end() ;){
            if((*it & last) == last) it = v.erase(it);
            else it++;
        }
    }
    return answer;
}

int main(){
    vector<vector<string>> v = {{"100","ryan","music","2"},
                                {"200","apeach","math","2"},
                                {"300","tube","computer","3"},
                                {"400","con","computer","4"},
                                {"500","muzi","music","3"},
                                {"600","apeach","music","2"}};

    printf("%d\n",solution(v));
}
