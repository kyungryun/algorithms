#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = -1;
    vector<pair<int, int>>foods;

    for(int i=0 ; i<food_times.size() ; i++){
        foods.push_back(make_pair(food_times[i], i+1));
    }
    sort(foods.begin(), foods.end());
    int cnt = food_times.size();
    int time = 0;
    for(vector<pair<int, int>>::iterator it=foods.begin() ; it != foods.end() ; it++,cnt--){
        long long s = (long long)(it->first - time) * cnt;
        if(s == 0) continue;
        if(s <= k){
            k-= s;
            time = it->first;
        }else{
            k %= cnt;
            sort(it, foods.end(), comp);
            return (it + k)->second;
        }
    }
    return answer;
}


int main(){

}
