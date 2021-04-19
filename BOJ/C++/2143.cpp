#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long t;
int n,m;
int a[1001];
int b[1001];
vector<long long> v1;
vector<long long> v2;
long long ans = 0;
int main(){
    scanf("%lld%d",&t,&n);
    for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0 ; i<m ; i++) scanf("%d",&b[i]);

    long long sum=0;
    for(int i=0 ; i<n ; i++){
        sum = a[i];
        v1.push_back(sum);
        for(int j=i+1 ; j<n ; j++){
            sum+=a[j];
            v1.push_back(sum);
        }
    }
    for(int i=0 ; i<m ; i++){
        sum = b[i];
        v2.push_back(sum);
        for(int j=i+1 ; j<m ; j++){
            sum+=b[j];
            v2.push_back(sum);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    long long start = 0;
    long long end = v2.size() - 1;
    while(1){
        if(v1[start] + v2[end] == t){
            long long aCnt = 1;
            long long bCnt = 1;

            while(start+1 <= v1.size()-1 && v1[start] == v1[start+1]){
                start++;
                aCnt++;
            }

            while(end-1 >= 0 && v2[end] == v2[end-1]){
                end--;
                bCnt++;
            }
            ans += aCnt*bCnt;
            start++;

        }
        if(start<= v1.size() - 1 && end >= 0 && v1[start] + v2[end] < t) start++;
        if(start<= v1.size() - 1 && end >= 0 && v1[start] + v2[end] > t) end--;
        if(start > v1.size() - 1 || end < 0) break;
    }
    printf("%lld\n",ans);
}
