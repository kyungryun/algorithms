#include <cstdio>
#include <map>
using namespace std;

int n,v;
map<int, int> m;
int main(){
    scanf("%d",&n);
    int t;
    for(int i=0 ; i<n ; i++){
        scanf("%d",&t);
        m[t]++;
    }
    scanf("%d",&v);
    printf("%d\n",m[v]);
}
