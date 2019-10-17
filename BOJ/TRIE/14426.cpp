#include <cstdio>
#include <cstring>

struct Trie{
    Trie *node[26];
    bool finish;
}a[100001];

int idx=0;
Trie *alloc(){
    for(int i=0 ; i<26 ; i++) a[idx].node[i] = 0;
    a[idx].finish = 0;
    return &a[idx++];
}
void insert(char *str, Trie *p){
    if(*str == 0){
        p->finish = true;
        return;
    }

    if(!p->node[*str-'a']){
        p->node[*str-'a'] = alloc();
    }
    insert(str+1, p->node[*str-'a']);
}

int find(char *str, Trie *p){
    if(*str == 0){
        return true;
    }

    if(!p->node[*str-'a']) return false;
    return find(str+1, p->node[*str-'a']);
}

int main(){
    int n,m;
    int ans = 0;
    scanf("%d%d",&n,&m);
    Trie *root = alloc();
    char str[501];
    for(int i=0 ; i<n ; i++){
        scanf("%s",str);
        insert(str, root);
    }
    for(int i=0 ; i<m ; i++){
        scanf("%s",str);
        ans += find(str, root);
    }

    printf("%d\n",ans);
}
