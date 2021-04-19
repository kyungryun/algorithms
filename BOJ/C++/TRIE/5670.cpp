#include <cstdio>
#include <cstring>

struct Trie{
    Trie *node[26];
    bool finish;
    int cnt;
}a[350000];

int idx=0;
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
    if(!p->node[*str-'a']){
        p->node[*str-'a'] = alloc();
        p->cnt++;
    }
    insert(str+1, p->node[*str-'a']);
}

int find(char *str, Trie *p, int cnt){
    if(*str == 0){
        return cnt;
    }
    if(p->cnt > 1 || p->finish) cnt++;
    return find(str+1, p->node[*str-'a'], cnt);
}

char str[100002][82];
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        idx = 0;
        for(int i=0 ; i<n ; i++){
            scanf("%s", str[i]);
        }
        Trie *root = alloc();
        for(int i=0 ; i<n ; i++){
            insert(str[i], root);
        }
        int ans = 0;
        if(root->cnt == 1) ans += n;
        for(int i=0 ; i<n ; i++){
            ans += find(str[i], root, 0);
        }
        printf("%.2lf\n",(double)ans/n);
    }
}
