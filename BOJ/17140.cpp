#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int r,c,k;
int mat[101][101];

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}
int main(){
    scanf("%d%d%d",&r,&c,&k);
    for(int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int time = 0;
    int nowR = 3;
    int nowC = 3;
    while(1){
        int temp[101][101]={0,};
        vector<pair<int, int> > v;
        int MAX = -1;
        if(mat[r][c] == k) break;
        if(time > 100){
            time = -1;
            break;
        }
        int size = 0;
        if(nowR >= nowC){
            for(int i=1 ; i<=nowR ; i++){
                v.clear();
                int num[101]={0,};
                for(int j=1 ; j<=nowC ; j++){
                    num[mat[i][j]]++;
                }
                for(int j=1 ; j<101 ; j++){
                    if(num[j] != 0){
                        v.push_back(make_pair(j,num[j]));
                    }
                }
                sort(v.begin(),v.end(),compare);
                size = v.size()*2;
                if(size > 100) size = 100;
                MAX = max(size, MAX);
                int idx = 0;
                for(int j=1 ; j<=size ; j+=2){
                    temp[i][j] = v[idx].first;
                    temp[i][j+1] = v[idx++].second;
                }
            }

            nowC = MAX;
        }else{
            for(int i=1 ; i<=nowC ; i++){
                v.clear();
                int num[101]={0,};
                for(int j=1 ; j<=nowR ; j++){
                    num[mat[j][i]]++;
                }
                for(int j=1 ; j<101 ; j++){
                    if(num[j] != 0){
                        v.push_back(make_pair(j,num[j]));
                    }
                }
                sort(v.begin(),v.end(),compare);
                size = v.size()*2;
                if(size > 100) size = 100;
                MAX = max(size, MAX);
                int idx = 0;
                for(int j=1 ; j<=size ; j+=2){
                    temp[j][i] = v[idx].first;
                     temp[j+1][i] = v[idx++].second;
                }
            }
            nowR = MAX;
        }
        for(int i=1 ; i<=nowR ; i++){
            for(int j=1 ; j<=nowC ; j++){
                mat[i][j] = temp[i][j];
            }
        }

        time++;
    }
    printf("%d\n",time);
}
