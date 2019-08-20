#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void lower_case(string &str){
    int i=0;
    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] += ('a'-'A');
        i++;
    }
}
void split(map<string, int> &m, string &str){
    for(int i=0 ; i<str.size()-1 ; i++){
        if((str[i] >= 'a' && str[i] <= 'z') && (str[i+1] >= 'a' && str[i+1] <= 'z')){
            if(m.find(str.substr(i,2)) != m.end()) m[str.substr(i, 2)]++;
            else m[str.substr(i,2)] = 1;
        }
    }
}
int solution(string str1, string str2) {
    int answer = 0;

    lower_case(str1);
    lower_case(str2);

    map<string, int> s1;
    map<string, int> s2;
    split(s1,str1);
    split(s2,str2);

    if(s1.empty() && s2.empty()) return 65536;
    map<string,int>::iterator it1;
    map<string,int>::iterator it2;
    int _union = 0;
    int inter = 0;
    for(it1 = s1.begin() ; it1 != s1.end() ; it1++){
        it2 = s2.find(it1->first);
        if(it2 != s2.end()){
            inter += min(it1->second, it2->second);
            _union += max(it1->second, it2->second);
            s2.erase(it2);
        }else{
            _union += it1->second;
        }
    }
    for(it2 = s2.begin() ; it2 != s2.end() ; it2++) _union += it2->second;
    answer = ((double)inter/_union)*65536;
    return answer;
}

int main(){
    string str1, str2;
    cin>>str1>>str2;
    cout<<solution(str1,str2)<<"\n";
}
