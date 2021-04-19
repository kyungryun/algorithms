#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;

int main(){
    cin>>n;
    for(int i=0 ; i<n ; i++){
        string t1,t2;
        cin>>t1>>t2;

        int a[1001] = {0,};
        for(int j=0 ; j<t1.size() ; j++) a[t1[j]-'a']++;
        for(int j=0 ; j<t2.size() ; j++) a[t2[j]-'a']--;

        bool flag = true;
        for(int j=0 ; j<26 ; j++){
            if(a[j] != 0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"Possible"<<"\n";
        else cout<<"Impossible"<<"\n";
    }
}
