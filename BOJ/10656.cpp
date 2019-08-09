#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char arr[51][51];
int n,m;
int idx[51][51];
int main(){
    scanf("%d%d",&n,&m);
    vector<pair<int, int>> v;
    for(int i=0 ; i<n ; i++){
        scanf("%s",arr[i]);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            bool flag = false;
            if(arr[i][j] == '#') continue;
            if(j == 0 || arr[i][j-1] == '#'){
                if(j+2 < m && arr[i][j+1] == '.' && arr[i][j+2] == '.') flag = true;
            }
            if(i == 0 || arr[i-1][j] == '#'){
                if(i+2 < n && arr[i+1][j] == '.' && arr[i+2][j] == '.') flag = true;
            }
            if(flag) v.push_back(make_pair(i+1,j+1));
        }

    }
    printf("%d\n",v.size());
    for(int i=0 ; i<v.size() ; i++){
        printf("%d %d\n",v[i].first, v[i].second);
    }
}
