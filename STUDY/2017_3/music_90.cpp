#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct INFO{
    int playTime;
    string title;
    string playMusic;
    string code;
    int cnt;
};
int hourToMin(string str){
    int hour = (str[0]-'0')*10 + (str[1]-'0');
    int min = (str[3]-'0')*10 + (str[4]-'0');
    min += hour*60;
    return min;
}
bool comp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){
    if(a.second.first == a.second.first) return a.second.second < b.second.second;
    return a.second.first > b.second.first;
}
string change(string str){
    string res;
    for(int i=0 ; i<str.size() ; ){
        if(str[i] == 'A' && str[i+1] == '#'){
            res += 'a';
            i+=2;
        }else if(str[i] == 'C' && str[i+1] == '#') {
            res += 'c';
            i+=2;
        }else if(str[i] == 'D' && str[i+1] == '#'){
            res += 'd';
            i+=2;
        }else if(str[i] == 'F' && str[i+1] == '#'){
            res += 'f';
            i+=2;
        }else if(str[i] == 'G' && str[i+1] == '#'){
            res += 'g';
            i+=2;
        }else res += str[i++];
    }
    return res;
}
string solution(string m, vector<string> musicinfos) {
    vector<pair<string, pair<int, int>>> answer;
    vector<INFO> info;
    string music = change(m);
    string t;

    for(int i=0 ; i<musicinfos.size() ; i++){
        INFO temp;
        temp.playTime = hourToMin(musicinfos[i].substr(6,5)) - hourToMin(musicinfos[i].substr(0,5));
        musicinfos[i] = musicinfos[i].substr(12);
        int j = 0;
        while(musicinfos[i][j] != ','){
            temp.title += musicinfos[i][j++];
        }
        j++;
        musicinfos[i] = musicinfos[i].substr(j);
        string t = change(musicinfos[i]);
        temp.code = t;
        string playMusic = "";
        int cnt = temp.playTime / temp.code.size();
        for(int j=0 ; j<temp.playTime ; j++){
            temp.playMusic += temp.code[j%temp.code.size()];
        }
        temp.cnt = cnt;
        info.push_back(temp);
    }


    for(int i=0 ; i<info.size() ; i++){
        if(info[i].playMusic.find(music) != string::npos){
            answer.push_back(make_pair(info[i].title,make_pair(info[i].cnt, i)));
        }
    }
    if(answer.size() != 0){
        sort(answer.begin(), answer.end(), comp);
        return answer[0].first;
    }else return "(None)";

}

int main(){
    vector<string> v = {{"03:00,03:30,FOO,CC#B"}, {"04:00,04:08,BAR,CC#BCC#BCC#B"}};
    vector<string> v2 = {{"12:00,12:14,HELLO,C#DEFGAB"}, {"13:00,13:05,WORLD,ABCDEF"}};
    vector<string> v3 = {{"12:00,12:14,HELLO,CDEFGAB"}, {"13:00,13:05,WORLD,ABCDEF"}};
    cout<<solution("CC#BCC#BCC#BCC#B", v)<<endl;

}
