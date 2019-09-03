#include <string>
#include <iostream>

using namespace std;

int an[26];
int bn[26];
int cnt;
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0 ; i<a.size() ; i++){
        an[a[i]-'a']++;
    }
    for(int i=0 ; i<b.size() ; i++){
        bn[b[i]-'a']++;
    }
    for(int i=0 ; i<26 ; i++){
        if(an[i] != bn[i]){
            cnt += abs(an[i] - bn[i]);
        }
    }
    cout<<cnt<<"\n";
}
