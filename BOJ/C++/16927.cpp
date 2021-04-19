#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void rotate();
int n, m, r;
int a[300][300];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	rotate();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
void rotate() {
	vector<int> v;
	int MIN = n < m ? n : m;
	for (int c = 0; c < MIN / 2; c++) {
		v.clear();
		int x1 = c, x2 = m - 1 - c, y1 = c, y2 = n - 1 - c;
		for (int col = 0; col < m - (2 * c); col++) v.push_back(a[y1][x1 + col]);
		for (int row = 1; row < n - (2 * c); row++) v.push_back(a[y1 + row][x2]);
		for (int col = 1; col < m - (2 * c); col++) v.push_back(a[y2][x2 - col]);
		for (int row = 1; row < n - (2 * c) - 1; row++) v.push_back(a[y2 - row][x1]);

		int index = r % v.size();

		for (int col = 0; col < m - (2 * c); col++) a[y1][x1 + col] = v[index++ % v.size()];
		for (int row = 1; row < n - (2 * c); row++) a[y1 + row][x2] = v[index++ % v.size()];
		for (int col = 1; col < m - (2 * c); col++) a[y2][x2 - col] = v[index++ % v.size()];
		for (int row = 1; row < n - (2 * c) - 1; row++) a[y2 - row][x1] = v[index++ % v.size()];
	}

}
