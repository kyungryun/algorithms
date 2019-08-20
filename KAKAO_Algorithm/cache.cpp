#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int size = cities.size();
    deque<string> lru;
    int lruSize = 0;
    for(int i=0 ; i<size ; i++){
        if(cacheSize == 0){
            answer = 5*size;
            break;
        }else{
            int j=0;
            while(cities[i][j] != '\0'){
                if(cities[i][j] >= 'A' && cities[i][j] <= 'Z'){
                    cities[i][j] += ('a'- 'A');
                }
                j++;
            }
            deque<string>::iterator iter;
            iter = find(lru.begin(), lru.end(), cities[i]);
            if(iter != lru.end()){
                answer++;
                string str = *iter;
                lru.erase(iter);
                lru.push_back(str);
            }else{
                answer+=5;
                if(lruSize == cacheSize){
                    lru.pop_front();
                    lruSize--;
                }
                lru.push_back(cities[i]);
                lruSize++;
            }
        }

    }
    return answer;
}
int main(){
    int c;
    vector<string>v;
    cin>>c;
    v.push_back("a");
    v.push_back("b");
    v.push_back("C");
    v.push_back("c");
    cout<<solution(c, v)<<"\n";
}
