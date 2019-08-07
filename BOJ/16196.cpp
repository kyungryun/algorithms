#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int code[51];
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
string s;
int year,month,day,zone,sex, checksum;
bool check(int y){
    return ((y%4==0)&&(y%100!=0) || y%400 == 0);
}
int main(){
    cin>>s>>n;
    for(int i=0 ; i<n ; i++){
        cin>>code[i];
    }
    int i=0;
    for( ; i<5 ; i++){
        zone += (s.at(i) - '0');
        zone*=10;
    }
    zone += (s.at(i++) - '0');

    for(; i<9 ; i++){
        year += s.at(i)-'0';
        year*=10;
    }
    year += s.at(i++) - '0';

    for(; i<11 ; i++){
        month += s.at(i)-'0';
        month *= 10;
    }
    month += s.at(i++) - '0';
    for(; i<13 ; i++){
        day += s.at(i) -'0';
        day *= 10;
    }
    day += s.at(i++) -'0';
    for(; i<16 ; i++){
        sex += s.at(i) - '0';
        sex *= 10;
    }
    sex += s.at(i++) - '0';
    if(s.at(i) == 'X') checksum = 10;
    else checksum = s.at(i)-'0';

    bool flag = false;
    for(int i=0 ; i<n ; i++){
        if(code[i] != zone) continue;
        flag = true;
    }

    if(!flag) {
        printf("I\n");
        return 0;
    }

    if(year < 1900 || year > 2011){
        printf("I\n");
        return 0;
    }
    if(month < 1 || month > 12){
        printf("I\n");
        return 0;
    }
    if(day <  1){
        printf("I\n");
        return 0;
    }
    if(check(year) && month == 2){
        if(day > 29){
            printf("I\n");
            return 0;
        }
    }else{
        if(day > days[month]){
            printf("I\n");
            return 0;
        }
    }
    if(sex == 0){
        printf("I\n");
        return 0;
    }
    int x = checksum;
    for(int i=0 ; i<17 ; i++){
        x += (s.at(i)-'0')*(1<<(17-i));
        x%=11;
    }
    if(x == 1){
        if(sex&1) printf("M\n");
        else printf("F\n");
    }else printf("I\n");
}
