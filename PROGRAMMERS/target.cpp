#include <string>
#include <vector>
#include <cstring>
using namespace std;

int tmp[21];
int answer;
int size;
bool visited[21];
vector<int> v;
void dfs(int idx, int cnt, int n, int target){
    if(cnt == n){
        int sum = 0;
        for(int i=0 ; i<size ; i++){
            if(visited[i]) sum -= tmp[i];
            else sum += tmp[i];
        }
        if(target == sum) answer++;

        return;
    }
    for(int i=idx ; i<size ; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, cnt+1, n, target);
            visited[i] = false;
        }
    }
}
void dfs2(int target, int cnt, int sum){
    if(cnt == size){
        if(sum == target) answer++;
        return;
    }
    dfs2(target, cnt+1, sum+tmp[cnt]);
    dfs2(target, cnt+1, sum-tmp[cnt]);
}
int solution(vector<int> numbers, int target) {
    size = numbers.size();
    for(int i=0 ; i<size ; i++) tmp[i] = numbers[i];
    /*for(int i=0 ; i<size ; i++){
        memset(visited, false, sizeof(visited));
        dfs(0, 0,i,target);
    }*/
    dfs2(target, 1, numbers[0]);
    dfs2(target, 1, -1*numbers[0]);
    return answer;
}


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    printf("%d\n",solution(v, 3));
}
