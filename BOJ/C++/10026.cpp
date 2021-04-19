#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
bool check[200][200];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool bli(bool blind, char f, char t) {
	if (f == t) return true;
	if (blind) {
		if (f == 'G' && t == 'R') return true;
		if (f == 'R' && t == 'G') return true;
	}
	return false;
}
int bfs(vector<string> &a, bool blind) {
	int n = a.size();
	bool check[200][200];
	memset(check, false, sizeof(check));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				ans++;
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				check[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
							if (check[nx][ny]) continue;
							if (bli(blind, a[x][y], a[nx][ny])) {
								check[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}

	return ans;
}
int main() {
	int n;
	cin >> n;

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << bfs(a, false) << ' ' << bfs(a, true) << '\n';
	
	
}