#include <iostream>
#include <string>
#include <set>
using namespace std;
struct Trie{
    Trie *node[26];
    bool finish;
    int cnt;
}a[600001];

int idx=0;
int dr[8] = {-1,-1,-1,0,1,1,1,0};
int dc[8] = {-1,0,1,1,1,0,-1,-1};
int score[9] = {0,0,0,1,1,2,3,5,11};
bool visited[4][4];
string board[4];
set<string> res;
Trie *alloc(){
    for(int i=0 ; i<26 ; i++) a[idx].node[i] = 0;
    a[idx].finish = 0;
    a[idx].cnt = 0;
    return &a[idx++];
}
void insert(char *str, Trie *p){
    if(*str == 0){
        p->finish = true;
        return;
    }
    if(!p->node[*str-'A']){
        p->node[*str-'A'] = alloc();
    }
    insert(str+1, p->node[*str-'A']);
}

void find(int r, int c, string str, Trie *p){
    if(r<0 || c <0 || r>=4 || c>=4) return;
    if(visited[r][c]) return;
    if(str.size()>=8) return;
    visited[r][c] = true;
    str = str + board[r][c];
    if(p->node[board[r][c] -'A'] == 0){
        visited[r][c] = false;
        return;
    }
    if(p->node[board[r][c]-'A']->finish) res.insert(str);
    for(int i=0 ; i<8 ; i++){
        find(r+dr[i], c+dc[i], str, p->node[board[r][c]-'A']);
    }
    visited[r][c] = false;
}
int main(){
    int w,b;
    cin>>w;
    char str[9];
    Trie *root = alloc();
    for(int i=0 ; i<w ; i++){
        cin>>str;
        insert(str, root);
    }
    getchar();
    cin>>b;

    while(b--){
        for(int i=0 ; i<4 ; i++){
            cin>>board[i];
        }
        res.clear();
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                find(i,j,"", root);
            }
        }
        string ans = *(res.begin());
        int total = 0;
        for(auto it : res){
            if(ans.size() < it.size()) ans = it;
            total += score[it.size()];
        }
        cout<<total<<" "<<ans<<" "<<res.size()<<"\n";
    }
}
