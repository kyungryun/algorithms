#include <string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> a;
stack<char> b;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int T=0 ; T<t ; T++){
        string l;
        cin>>l;
        for(int i=0 ; i<l.size() ; i++){
            char c = l[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) a.push(c);
            if(c == '<' && !a.empty()){
                b.push(a.top());
                a.pop();
            }
            if(c == '>' && !b.empty()){
                a.push(b.top());
                b.pop();
            }
            if(c == '-' && !a.empty()){
                a.pop();
            }
        }
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        while(!b.empty()){
            cout<<b.top();
            b.pop();
        }
        cout<<"\n";
    }
}
