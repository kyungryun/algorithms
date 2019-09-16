#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


bool comp(string a, string b){
    return a > b;
}
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> m;
    cin>>n;
    string name,state;
    for(int i=0 ; i<n ; i++){
        cin>>name>>state;
        m[name] = state;
    }
    vector<string> v;
    for(auto it = m.begin() ; it != m.end() ; it++){
        if(it->second == "enter"){
            v.push_back(it->first);
        }
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<"\n";
    }
}
