#include <cstdio>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;


string a;
string t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    cin>>t;

    int lidx = 0;
    int ridx = t.size()-1;
    deque<char> ldq;
    deque<char> rdq;
    while(lidx <= ridx){
        while(lidx <= ridx){
            ldq.push_back(t.at(lidx++));
            if(ldq.size() >= a.size()){
                bool flag = true;
                for(int i=0 ; i<a.size() ; i++){
                    if(ldq[ldq.size() - a.size() + i] != a[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int i=0 ; i<a.size() ; i++) ldq.pop_back();
                    break;
                }
            }
        }
        while(lidx <= ridx){
            rdq.push_front(t.at(ridx--));
            if(rdq.size() >= a.size()){
                bool flag = true;
                for(int i=0 ; i<a.size() ; i++){
                    if(rdq[i] != a[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int i=0 ; i<a.size() ; i++)rdq.pop_front();
                    break;
                }
            }
        }
    }
    string res;
    for(int i=0 ; i<ldq.size() ; i++){
        res += ldq[i];
    }
    for(int i=0 ; i<rdq.size() ; i++){
        res += rdq[i];
    }
    while(res.find(a) != string::npos) res.erase(res.find(a), a.size());
    cout<<res<<"\n";
}
