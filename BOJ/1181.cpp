#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> str;
bool comp(string a, string b){
    if(a.size() == b.size()) return a<b;
    return a.size() < b.size();
}
int main(){
    int n;
    cin>>n;

    for(int i=0 ; i<n ; i++){
        string s;
        cin>>s;
        str.push_back(s);
    }
    sort(str.begin(),str.end(), comp);
    str.erase(unique(str.begin(),str.end()),str.end());
    for(int i=0 ; i<str.size() ; i++){
        cout<<str[i]<<"\n";
    }
}
