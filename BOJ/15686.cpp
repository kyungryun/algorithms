#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
int map[51][51];
vector<pair<int, int>> ch;
vector<pair<int, int>> home;
vector<pair<int, int>> sel;
int homeCnt;
int ans = 987654321;
void calc(){
    int size = sel.size();
    int tmp = 0;
    for(int i=0 ; i<homeCnt ; i++){
        int MIN = 987654321;
        for(int j=0 ; j<size ; j++){
            MIN = min(MIN, abs(home[i].first - sel[j].first) + abs(home[i].second - sel[j].second));
        }
        tmp += MIN;
    }
    ans = min(ans, tmp);
}
void dfs(int cnt, int idx){
    if(cnt == m){
        calc();
        return;
    }
    int size = ch.size();
    for(int i=idx ; i<size ; i++){
        if(map[ch[i].first][ch[i].second] == 2){
            sel.push_back(make_pair(ch[i].first,ch[i].second));
            printf("%d %d %d\n",i, ch[i].first, ch[i].second);
            dfs(cnt+1, i+1);
            sel.pop_back();
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);

    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2) ch.push_back(make_pair(i,j));
            else if(map[i][j] == 1) home.push_back(make_pair(i,j));
        }
    }
    homeCnt = home.size();
    dfs(0, 0);
    printf("%d\n",ans);
}
