#include <cstdio>
#include <vector>

using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end){
    if(start == end) return tree[node] = arr[start];

    int mid = (start+end)/2;

    return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(!(start<= index && index <= end)) return;

    tree[node] += diff;

    if(start != end){
        int mid = (start + end)/2;
        update(tree,node*2,start,mid,index,diff);
        update(tree,node*2+1,mid+1,end,index,diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;

    if(left <=start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}


int main(){
    int n,m,k;
    int tree_size;
    scanf("%d %d %d",&n,&m,&k);
    tree_size = n*4;
    vector<long long> arr(n);
    vector<long long> tree(tree_size);

    for(int i=0 ; i<n ; i++){
        scanf("%lld",&arr[i]);
    }
    init(arr, tree, 1, 0, n-1);

    m+=k;
    while(m--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int idx;
            long long num;
            scanf("%d%lld",&idx,&num);
            long long diff = num - arr[idx-1];
            arr[idx-1] = num;
            update(tree,1,0,n-1,idx-1, diff);
        }else if(op == 2){
            int l,r;
            scanf("%d%d",&l,&r);
            --l,--r;
            printf("%lld\n",sum(tree, 1, 0, n-1, l , r));
        }
    }
    return 0;

}
