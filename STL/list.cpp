#include <cstdio>

using namespace std;

const int LIST_SIZE = 30000;

struct NODE{
    int next;
    int prev;
    int data;
};

struct MY_LIST{
    int HEAD = LIST_SIZE;
    int TAIL = LIST_SIZE + 1;
    int pos;
    NODE node[LIST_SIZE + 2];

    MY_LIST(){
        pos = 0;
        node[HEAD].next = TAIL;
        node[TAIL].prev = HEAD;
    }

    void push_node_change(int next, int prev, int pos, int data){
        node[pos].data = data;

        node[pos].prev = prev;
        node[prev].next = pos;

        node[pos].next = next;
        node[next].prev = pos;
    }
    void pop_node_change(int next, int prev, int target){
        node[prev].next = next;
        node[next].prev = prev;

    }
    void push_back(int data){
        int prev = node[TAIL].prev;
        int next = node[prev].next;

        push_node_change(next, prev, pos, data);
        pos++;
    }
    void push_front(int data){
        int next = node[HEAD].next;
        int prev = node[next].prev;

        push_node_change(next, prev, pos, data);
        pos++;
    }
    void insert(int p, int data){
        int next = node[HEAD].next;
        for(int i=0 ; i<p ; i++) next = node[next].next;
        int prev = node[next].prev;

        push_node_change(next, prev, pos, data);
        pos++;
    }

    void pop_back(){
        int target = node[TAIL].prev;

        int next = node[target].next;
        int prev = node[target].prev;

        pop_node_change(next, prev, target);
        pos--;
    }
    void pop_front(){
        int target = node[HEAD].next;

        int next = node[target].next;
        int prev = node[target].prev;

        pop_node_change(next, prev, target);
        pos--;
    }
    void erase(int p){
        int target = node[HEAD].next;
        for(int i=0 ; i<p ; i++) target = node[target].next;
        int prev = node[target].prev;
        int next = node[target].next;

        pop_node_change(next, prev, target);
        pos--;
    }
    int front(){
        return node[node[HEAD].next].data;
    }
    int back(){
        return node[node[TAIL].prev].data;
    }
    int size(){
        return pos;
    }
};

int main(){
    MY_LIST list;
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        int t;
        scanf("%d",&t);
        list.push_back(t);
    }
    printf("%d %d %d\n", list.front(), list.back(), list.size());
    for(int i = list.node[list.HEAD].next ; i !=list.TAIL  ; i=list.node[i].next){
        printf("%d ",list.node[i].data);
    }
    printf("\n");
}
