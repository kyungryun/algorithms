#include <cstdio>
#include <queue>
#include <map>
 
using namespace std;
 
queue <pair<int, int>> q;
map<int, int> m; 
int visit[200001];
int MAX = 100000;

int main()
{
    int pos, target;
    scanf("%d %d", &pos, &target);
 
    q.push(make_pair(0, pos));
 
    int ans = 987654321;
    int cnt = 0;
 
    if (pos == target)
        printf("0\n1");
    else{
        while (!q.empty()){
            int x = q.front().second;
            int cnt = q.front().first;
 
            q.pop();
            visit[x] = 1;
 
            if (x == target){
                    m[cnt]++;
                    ans = min(ans, cnt);
            }
            if (x * 2 <= MAX && x * 2 >= 0 && visit[x * 2] == 0)
                q.push(make_pair(cnt + 1, x * 2));
 
            if (x - 1 >= 0 && x - 1 <= MAX && visit[x - 1] == 0)
                q.push(make_pair(cnt + 1, x - 1));
 
            if (x + 1 <= MAX && x + 1 >= 0 && visit[x + 1] == 0)
                q.push(make_pair(cnt + 1, x + 1));
 
        }
        printf("%d\n%d", ans, m[ans]);
    }
 
    return 0;
}
