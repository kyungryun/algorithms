#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
void update(vector<int> &tree, int node, int start, int end, int idx, int value){
    if(start > idx || end < idx) return;

    tree[node] = value;
    if(start != end){
        int mid = (start+end)>>1;
        update(tree, node*2, start, mid, idx, value);
        update(tree,node*2+1, mid+1, end, idx, value);

        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}
int query(vector<int> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;

    if(left <= start && end <= right) return tree[node];

    int mid = (start + end)>>1;
    return  max(query(tree,node*2, start, mid, left, right), query(tree,node*2+1, mid+1, end, left, right));
}
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int, int>> arr;
    vector<int> tree(n*4);
    for(int i=0 ; i<n ; i++){
        int tmp;
        scanf("%d",&tmp);
        arr.push_back(make_pair(tmp,i));
    }

    sort(arr.begin(),arr.end(),comp);

    int idx = 0;
    bool flag = false;
    int len = 0;
    for(int i=0 ; i<n ; i++){
        int lis = query(tree,1,0,n-1,0,arr[i].second);
        update(tree,1,0,n-1,arr[i].second, lis+1);
    }
    printf("%d\n",tree[1]);
}
