#include <cstdio>
#include <cstring>

struct Trie{
    Trie *next[11];
    bool finish;
}a[100005];

int idx=0;

Trie *trie;
Trie* myalloc(){
    for(int i=0 ; i<11 ; i++) a[idx].next[i] = nullptr;
    a[idx].finish = 0;
    return &a[idx++];
}

void insert(char *str, Trie *trie){
    int len = strlen(str);
    for(int i=0 ; i<len ; i++){
        if(!trie->next[str[i]-'0']){
            trie->next[str[i]-'0'] = myalloc();
        }
        trie = trie->next[str[i]-'0'];
    }
    trie->finish = true;
}
bool find(char *str, Trie *trie){
    int len = strlen(str);
    for(int i=0 ; i<len ; i++){
        if(trie->next[str[i]-'0'] == nullptr) return false;
        if(trie->finish) return true;
        trie = trie->next[str[i]-'0'];
    }
    return false;
}
void init(){
    idx = 0;
    trie = nullptr;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char call[10001][11];
        int n;
        init();
        scanf("%d",&n);

        for(int i=0 ; i<n ; i++){
            scanf("%s",call[i]);
        }
        trie = myalloc();

        for(int i=0 ; i<n ; i++){
            insert(call[i], trie);
        }

        bool flag = false;
        for(int i=0 ; i<n ; i++){
            if(find(call[i], trie)){
                flag = true;
            }
        }
        printf("%s\n",flag?"NO":"YES");
    }
}
