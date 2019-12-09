#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(){
    int T;
    cin>>T;

    for(int t=1 ; t<=T ; t++){
        int k;
        string str;
        vector<string> v;
        cin>>k>>str;
        int size = str.length();
        for(int i=0 ; i<size ; i++){
            v.push_back(str);
            str = str.substr(1);
        }
        sort(v.begin(),v.end());
        cout<<"#"<<t<<" "<<v[k-1]<<"\n";
    }

}
