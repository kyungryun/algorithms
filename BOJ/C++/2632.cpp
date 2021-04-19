#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int buy;
int n,m;
int a[1001];
int b[1001];
vector<int> v1;
vector<int> v2;
long long ans = 0;
int main(){
    scanf("%d",&buy);
    scanf("%d%d",&m,&n);
    for(int i=0 ; i<m ; i++) scanf("%d",&a[i]);
    for(int i=0 ; i<n ; i++) scanf("%d",&b[i]);

    int start=0;
    int end = 0;
    int sum = 0;
    while(start<m){
        sum += a[end++];
        if(sum <= buy) v1.push_back(sum);
        else{
            start++;
            end = start;
            sum = 0;
        }

        if(end == m) end = 0;

        if(end + 1 == start || (start == 0 && end == 0)){
            start++;
            end = start;
            sum = 0;
        }
    }
    start = 0;
    end = 0;
    sum = 0;
    while(start<n){
        sum += b[end++];
        if(sum <= buy) v2.push_back(sum);
        else{
            start++;
            end = start;
            sum = 0;
        }

        if(end == n) end = 0;

        if(end + 1 == start || (start == 0 && end == 0)){
            start++;
            end = start;
            sum = 0;
        }
    }
    v1.push_back(0);
    v2.push_back(0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(int i=0 ; i<v1.size() ; i++){
        vector<int>::iterator l = lower_bound(v2.begin(), v2.end(), buy - v1[i]);
        vector<int>::iterator u = upper_bound(v2.begin(), v2.end(), buy - v1[i]);
        ans += (u-l);
    }
    printf("%lld\n",ans);
}
