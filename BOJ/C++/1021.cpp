#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n,m;
deque<int> v;

int ans;
int main(){
    scanf("%d%d",&n,&m);
    int t;
    for(int i=1 ; i<=n ; i++){
        v.push_back(i);
    }
    for(int i=0 ; i<m ; i++){
        scanf("%d",&t);
        int idx = 1;
        for(deque<int>::iterator it = v.begin() ; it != v.end() ; it++){
            if(*it == t) break;
            idx++;
        }

        int left = idx-1;
        int right = v.size() - idx+1;
        if(left < right){
            for(int i=0 ; i<left ; i++){
                int tmp = v.front();
                v.push_back(tmp);
                v.pop_front();
                ans++;
            }
            v.pop_front();
        }else{
            for(int i=0 ; i<right ; i++){
                int tmp = v.back();
                v.push_front(tmp);
                v.pop_back();
                ans++;
            }
            v.pop_front();
        }
    }
    printf("%d\n",ans);
}
