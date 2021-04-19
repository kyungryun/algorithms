#include <cstdio>
#include <vector>
using namespace std;

int n,p,ans;
vector<int> v;
bool flag;
int main(){
    scanf("%d%d",&n,&p);
    v.push_back(n);
    while(1){
        int size = v.size();
        int cur = (v[size-1]*n)%p;
        ans++;
        for(int i=0 ; i<size ; i++){
            if(v[i] == cur){
                ans -= i;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
        v.push_back(cur);
    }
    printf("%d\n",ans);
}