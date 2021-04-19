#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 987654321;
int n,m;
int people[11];
vector<int> area[11];
bool visitA[11], visitB[11];
bool checkA[11], checkB[11];
void dfsA(int cnt){
    if(visitA[cnt]) return;
    visitA[cnt] = true;
    for(int i=0 ; i<area[cnt].size() ; i++){
        int now = area[cnt][i];
        if(!visitA[now] && checkA[now]){
            dfsA(now);
        }
    }
    return;
}
void dfsB(int cnt){
    if(visitB[cnt]) return;
    visitB[cnt] = true;
    for(int i=0 ; i<area[cnt].size() ; i++){
        int now = area[cnt][i];
        if(!visitB[now] && checkB[now]){
            dfsB(now);
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++) scanf("%d",&people[i]);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&m);
        int num;
        for(int j=0 ; j<m ; j++){
            scanf("%d",&num);
            area[i].push_back(num-1);
        }
    }
    int ans = INF;
    for(int i=1 ; i<(1<<n) - 1 ; i++){
        memset(visitA,false,sizeof(visitA));
        memset(visitB,false,sizeof(visitB));
        memset(checkA,false,sizeof(checkA));
        memset(checkB,false,sizeof(checkB));
        int a[11], b[11];
        int asum = 0, bsum = 0;
        int aidx = 0, bidx = 0;
        for(int j=0 ; j<n ; j++){
            if(i & 1<<j){
                a[aidx++] = j;
                asum += people[j];
                checkA[j] = true;
            }else{
                b[bidx++] = j;
                bsum += people[j];
                checkB[j] = true;
            }
        }
        dfsA(a[0]);
        bool flag = true;
        for(int j=0 ; j<aidx ; j++){
            if(!visitA[a[j]]){
                flag = false;
                break;
            }
        }
        if(!flag) continue;

        dfsB(b[0]);
        for(int j=0 ; j<bidx ; j++){
            if(!visitB[b[j]]){
                flag = false;
                break;
            }
        }
        if(!flag) continue;

        ans = min(ans, abs(asum-bsum));
    }
    printf("%d\n",ans == INF ? -1 : ans);
}
