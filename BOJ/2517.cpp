#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void update(vector<int> &tree, int node, int start, int end, int index){
    if(!(start<= index && index <= end)) return;

    tree[node] += 1;

    if(start != end){
        int mid = (start + end)/2;
        update(tree,node*2,start,mid,index);
        update(tree,node*2+1,mid+1,end,index);
    }
}

int query(vector<int> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;

    if(left <=start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(tree, node*2, start, mid, left, right) + query(tree, node*2+1, mid+1, end, left, right);
}

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int, int>> v;
    int num;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&num);
        v.push_back(make_pair(num,i));
    }
    sort(v.begin(),v.end());
    for(int i=0 ; i<n ; i++){
        v[i].first = i;
    }
    sort(v.begin(),v.end(),comp);
    vector<int> tree(500000*4);
    for(int i=0 ; i<n ; i++){
        int ans = i - query(tree,1,0,500000,0,v[i].first) + 1;
        printf("%d\n",ans);
        update(tree,1,0,500000,v[i].first);
    }
    return 0;

}
