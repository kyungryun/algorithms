#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t,tc,len;
    scanf("%d",&t);
    char c;
    map<string, int > m;
    m["ZRO"] = 0;
    m["ONE"] = 1;
    m["TWO"] = 2;
    m["THR"] = 3;
    m["FOR"] = 4;
    m["FIV"] = 5;
    m["SIX"] = 6;
    m["SVN"] = 7;
    m["EGT"] = 8;
    m["NIN"] = 9;

    for(int T=1 ; T<=t ; T++){
        vector<pair<int, string>> v;
        string str;
        scanf(" %c",&c);
        scanf("%d%d",&tc,&len);
        for(int i=0 ; i<len ; i++){
            cin>>str;
            v.push_back(make_pair(m[str],str));
        }
        sort(v.begin(), v.end());
        printf("#%d ",tc);
        for(int i=0 ; i<len ; i++) cout<<v[i].second<<" ";
        cout<<endl;
    }
}
