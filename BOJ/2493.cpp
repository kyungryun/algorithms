#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int n;
int arr[500001];
int ans[500001];
int main(){
    scanf("%d",&n);
    stack<pair<int, int>> s;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0 ; i<n ; i++){
        while(!s.empty()){
            if(s.top().second > arr[i]){
                ans[i] = s.top().first+1;
                break;
            }
            s.pop();
        }
        if(s.empty()) ans[i] = 0;
        s.push(make_pair(i,arr[i]));
    }
    for(int i=0 ; i<n ; i++) printf("%d ",ans[i]);
    printf("\n");
}
