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
        int b[1001] = {0,};
        if(t1.size() != t2.size()) cout<<"Impossible"<<"\n";
        else{
            for(int j=0 ; j<t1.size() ; j++){
                a[t1[j]-'a']++;
                b[t2[j]-'a']++;
            }
            bool flag = true;
            for(int j=0 ; j<26 ; j++){
                if(a[j] != b[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) cout<<"Possible"<<"\n";
            else cout<<"Impossible"<<"\n";
        }
    }
}
