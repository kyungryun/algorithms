// 셔틀버스
// https://programmers.co.kr/learn/courses/30/lessons/17678

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int timeToMin(string time){
    int min = ((time[0] - '0')*10 + time[1] - '0')*60 +
                (time[3] - '0')*10 + time[4] - '0';

    return min;
}
string minToTime(int time){
    string hour = "";
    string min = "";
    if(time/60 < 10) hour+="0";
    if(time%60 < 10) min+="0";
    hour += to_string(time/60);
    min += to_string(time%60);
    return hour + ':' + min;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    deque<int> dq;
    int size = timetable.size();
    for(int i=0 ; i<size ; i++){
        dq.push_back(timeToMin(timetable[i]));
    }

    int time = 9*60;
    int ride = time;
    int cnt = 1;
    sort(dq.begin(), dq.end());
    while(1){
        int shuttle = 0;
        size = dq.size();
        vector<int> v;
        for(int i=0 ; i<size ; i++){
            if(dq[i] <= time && shuttle < m) {
                shuttle++;
                v.push_back(dq[i]);
            }
        }
        if(shuttle != 0){
            dq.erase(dq.begin(), dq.begin()+shuttle);
        }
        if(v.empty()) v.push_back(time);
        if(cnt == n){
            if(shuttle < m) ride = time;
            else ride = v.back()-1;
            break;
        }
        cnt++;
        time += t;
    }
    return minToTime(ride);
}


int main(){
    int n,m,t,a;
    vector<string>str;
    cin>>n>>t>>m>>a;
    for(int i=0 ; i<a ; i++){
        string tmp;
        cin>>tmp;
        str.push_back(tmp);
    }
    cout<<solution(n,t,m,str)<<endl;
}

/*
1 1 5 4
08:00
08:01
08:02
08:03

2 10 2 3
09:10
09:09
08:00

1 1 1 1
23:59

10 60 45 16
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59
23:59

2 1 2 4
09:00
09:00
09:00
09:00

*/
