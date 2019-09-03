#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
vector<int> man;
vector<int> woman;
int ans;
void calc(vector<int> &v){
    for(int i=1 ; i<=6 ; i++){
        vector<int>::iterator l = lower_bound(v.begin(), v.end(),i);
        vector<int>::iterator u = upper_bound(v.begin(), v.end(), i);
        if((u-l) == 0) continue;
        if((u-l) <= k) ans++;
        else{
            if((u-l) % k == 0) ans += (u-l)/k;
            else{
                ans += (u-l)/k + 1;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    int y, s;
    for(int i=0 ; i<n ; i++){
        scanf("%d%d",&s,&y);
        if(s == 0) woman.push_back(y);
        else man.push_back(y);
    }
    sort(woman.begin(), woman.end());
    sort(man.begin(), man.end());
    calc(woman);
    calc(man);
    printf("%d\n",ans);
}
