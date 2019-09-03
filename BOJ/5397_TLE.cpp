#include <string>
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int T=0 ; T<t ; T++){
        string l;
        cin>>l;

        string p = "";
        int cur = 0;
        for(int i=0 ; i<l.size() ; i++){
            if(isdigit(l[i]) ||(l[i] >= 'a' && l[i] <= 'z') || (l[i] >= 'A' && l[i] <= 'Z')){
                p.insert(cur++, 1, l[i]);
            }else{
                if(l[i] == '<'){
                    if(cur > 0) cur--;
                }else if(l[i] == '>'){
                    if(cur < p.size()) cur++;
                }else{
                    if(p.size() != 0 && cur > 0) p.erase(--cur, 1);
                }
            }
        }
        cout<<p<<"\n";
    }
}
