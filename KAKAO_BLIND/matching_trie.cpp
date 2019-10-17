#include <string>
#include <vector>
#include <cstring>
using namespace std;

struct Trie{
    bool finish;
    Trie *word[27];
    int cnt;
}a[1000001];
int idx = 0;
Trie *alloc(){
    for(int i=0 ; i<27 ; i++) a[idx].word[i] = 0;
    a[idx].finish = 0;
    a[idx].cnt = 0;
    return &a[idx++];
}
Trie *root;
int toNumber(char s){
    if(s == '?') return 26;

    return s-'a';
}
void insert(const char *str){
    Trie *p = root;
    int len = strlen(str);
    for(int i=0 ; i<len ; i++){
        int key = toNumber(str[i]);
        if(!p->word[key]){
            p->word[key] = alloc();
        }
        p = p->word[key];
    }
    p->finish = true;
}
void find(const char *str, Trie *p){
    if(*str == 0){
        p->cnt++;
        return;
    }
    int next = toNumber(*str);
    if(p->word[toNumber('?')]) find((str+1), p->word[toNumber('?')]);
    if(p->word[next]) find((str+1), p->word[next]);
}
int getCnt(const char *str, Trie *p){
    if(*str == 0){
        return p->cnt;
    }
    int next = toNumber(*str);
    if(!p->word[next]) return 0;
    return getCnt(str+1, p->word[next]);
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    root = alloc();
    for(int i=0 ; i<queries.size() ; i++){
        insert(queries[i].c_str());
    }
    for(int i=0 ; i<words.size() ; i++){
        find(words[i].c_str(), root);
    }
    for(int i=0 ; i<queries.size() ; i++){
        answer.push_back(getCnt(queries[i].c_str(), root));
    }
    return answer;
}

int main(){
    vector<string> w = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> q = {"fro??", "????o", "fr???", "fro???", "pro?"};
    vector<int> ans = solution(w,q);

}
