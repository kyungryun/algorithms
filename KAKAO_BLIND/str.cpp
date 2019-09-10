#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string w){
    stack<char> s;
    for(int i=0 ; i<w.size() ; i++){
        if(w[i] == '(') s.push(w[i]);
        else{
            if(!s.empty()){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}
pair<string, string> split(string w){
    stack<char> s;
    string u="";
    string v="";
    int l = 0;
    int r = 0;
    for(int i=0 ; i<w.size();  i++){
        if(w[i] == '(') {
            u+=w[i];
            l++;
        }
        else{
            u+=w[i];
            r++;
        }
        if(l == r) break;
    }
    v = w.substr(u.size());
    return make_pair(u,v);
}
string dfs(string w){
    if(w.size() == 0) return "";
    pair<string, string> str = split(w);
    string u = str.first;
    string v = str.second;
    if(check(u)){
        v = dfs(v);
        return u + v;
    }else{
        string str = "";
        str += '(';
        str += dfs(v);
        str += ')';
        u = u.substr(1, u.size()-2);
        for(int i=0 ; i<u.size() ; i++){
            if(u[i] == '(') str+= ')';
            else str+= '(';
        }
        return str;
    }
    return v;
}
string solution(string p) {
    if(check(p)){
        return p;
    }else{
        return dfs(p);
    }
}
