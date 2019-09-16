#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int mod = 1e9+7;
const int prime = 5381;

int hp,wp,hm,wm;
vector<string> p;
vector<string> m;
string str;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin>>hp>>wp>>hm>>wm;

    for(int i=0 ; i<hp ; i++){
        cin>>str;
        p.push_back(str);
    }
    for(int i=0 ; i<hm ; i++){
        cin>>str;
        m.push_back(str);
    }
    map<vector<string>, int> hash;
    for(int i=0 ; i<=hm-hp ; i++){
        for(int j=0 ; j<=wm-wp ; j++){
            if(m[i].substr(j,wp) != p[0]) continue;
            vector<string> temp;
            for(int k=i ; k<hp+i ; k++){
                temp.push_back(m[k].substr(j,wp));
            }
            hash[temp]++;
        }
    }
    cout<<hash[p]<<"\n";
}
