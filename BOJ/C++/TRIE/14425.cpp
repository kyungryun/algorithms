#include <cstdio>
#include <cstring>

struct Trie{
    bool fin;
    Trie *next[26];
}a[5000000];

int idx = 0;
Trie *root;
Trie *alloc(){
    for(int i=0 ; i<26 ; i++){
        a[idx].next[i] = nullptr;
    }
    a[idx].fin = 0;
    return &a[idx++];
}
int ztrlen(char *str){
    int cnt = 0;
    while(*str++) cnt++;
    return cnt;
}
void insert(char *str){
    int len = ztrlen(str);
    Trie *p = root;
    for(int i=0 ; i<len ; i++){
        if(!p->next[str[i]-'a']){
            p->next[str[i]-'a'] = alloc();
        }
        p = p->next[str[i]-'a'];
    }
    p->fin = true;
}
bool find(char *str){
    int len = ztrlen(str);
    Trie *p = root;
    for(int i=0 ; i<len ; i++){
        if(p->next[str[i]-'a'] == nullptr) return false;
        p = p->next[str[i]-'a'];
    }
    if(p->fin) return true;
    else return false;
}
int main(){
    int n,m;
    char str[502];
    scanf("%d%d",&n,&m);

    root = alloc();
    for(int i=0 ; i<n ; i++){
        scanf("%s",str);
        insert(str);
    }
    int ans = 0;
    for(int i=0 ; i<m ; i++){
        scanf("%s",str);
        if(find(str)) ans++;
    }
    printf("%d\n",ans);
}
