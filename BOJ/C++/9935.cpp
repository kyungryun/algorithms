#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;


string a;
string b;
char res[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    cin>>b;
    int idx = 0;
    for(int i=0 ; i<a.size() ; i++){
        res[idx++] = a.at(i);
        int last = b.size()-1;
        if(a.at(i) == b.at(last)){
            bool flag = true;
            int s = idx - b.size();
            for(int k=idx-1 ; k>= s ; k--){
                if(res[k] != b.at(last--)){
                    flag = false;
                    break;
                }
            }
            if(flag) idx -= b.size();
        }
    }
    if(idx == 0) cout<<"FRULA"<<endl;
    else{
        for(int i=0 ; i<idx ; i++){
            cout<<res[i];
        }
        cout<<endl;
    }
}
