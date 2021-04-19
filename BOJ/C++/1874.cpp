#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int n,t;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&t);
        v.push_back(t);
    }

    stack<int> s;
    vector<char> op;
    int j=0;
    for(int i=1 ; i<=n ; i++){
        s.push(i);
        op.push_back('+');
        while(!s.empty()){
            if(v[j] != s.top()) break;
            else{
                s.pop();
                op.push_back('-');
                j++;
            }
        }
    }

    if(s.empty()){
        for(int i=0 ; i<op.size() ; i++) printf("%c\n",op[i]);
    }else{
        printf("NO\n");
    }
}
