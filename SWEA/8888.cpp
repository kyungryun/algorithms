#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct RANK{
    int num;
    int score;
    int solve;
};

bool comp(const RANK &a, const RANK &b){
    if(a.score == b.score){
        if(a.solve == b.solve) return a.num < b.num;
        else return a.solve > b.solve;
    }else return a.score > b.score;
}
int person[2001][2001];
int problem[2001];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int testcase;
    cin>>testcase;
    for(int tc = 1 ; tc<=testcase ; tc++){
        int n,t,p;
        cin>>n>>t>>p;
        RANK rank[n];
        memset(problem, 0, sizeof(problem));
        memset(rank, 0, sizeof(rank));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<t ; j++){
                cin>>person[i][j];
                if(person[i][j] == 0) problem[j]++;
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<t ; j++){
                rank[i].num = i;
                if(person[i][j] == 1){
                    rank[i].score += problem[j];
                    rank[i].solve++;
                }
            }
        }
        sort(rank, rank+n, comp);
        for(int i=0 ; i<n ; i++){
            if(rank[i].num == p-1){
                cout<<"#"<<tc<<' '<<rank[i].score<<' '<<i+1<<'\n';
                break;
            }
        }
    }
}
