#include <cstdio>

struct Trie{
    Trie *node[128];
    bool finish;
    bool checked;
}a[50001];


int idx = 0;
int ans = 0;
Trie *alloc(){
    for(int i=0 ; i<128 ; i++) a[idx].node[i] = 0;
    a[idx].finish = 0;
    a[idx].checked = 0;
    return &a[idx++];
}

void insert(char *str, Trie *p, bool check){
    if(*str == 0){
        p->checked = check;
        p->finish = check;
        return;
    }

    int next = *str;
    if(!p->node[next]){
        p->node[next] = alloc();
    }
    p->finish = check;
    insert(str+1, p->node[next], check);
}
void find(Trie *p){
    if(p->finish){
        ans++;
        return;
    }else if(p->checked) ans++;

    for(int i=0 ; i<128 ; i++){
        if(p->node[i]) find(p->node[i]);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        idx = 0;
        ans = 0;
        char str[21];
        Trie *root = alloc();
        scanf("%d",&n);

        for(int i=0 ; i<n ; i++){
            scanf("%s",str);
            insert(str, root, true);
        }

        scanf("%d",&m);

        for(int i=0 ; i<m ; i++){
            scanf("%s",str);
            insert(str, root, false);
        }
        find(root);
        printf("%d\n",ans);
    }
}
